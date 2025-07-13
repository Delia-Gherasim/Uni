using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace practic
{
    public partial class Form1 : Form
    {
        SqlConnection sqlConnection;
        SqlDataAdapter dataAdapterClients;
        SqlDataAdapter dataAdapterBrokerages;
        DataSet dset;
        BindingSource bsClients;
        BindingSource bsBrokerages;
        SqlCommandBuilder sqlCommandBuilder;

        string queryClients;
        string queryBrokerage;

        public Form1()
        {
            InitializeComponent();
            FillData();
        }

        private void FillData()
        {
            sqlConnection = new SqlConnection("Data Source=DESKTOP-G5O4MNS\\SQLEXPRESS;" + "Initial Catalog=practic; Integrated Security=true;");
            queryClients = "Select * from Clients";
            queryBrokerage = "Select * from Brokerage";

            dataAdapterClients = new SqlDataAdapter(queryClients, sqlConnection);
            dataAdapterBrokerages = new SqlDataAdapter(queryBrokerage, sqlConnection);

            dset = new DataSet();
            dataAdapterClients.Fill(dset, "Clients");
            dataAdapterBrokerages.Fill(dset, "Brokerage");

            sqlCommandBuilder = new SqlCommandBuilder(dataAdapterClients);

            dset.Relations.Add("ClientsBrokerage", dset.Tables["Brokerage"].Columns["clientId"], dset.Tables["Clients"].Columns["clientId"]);

            bsBrokerages = new BindingSource();
            bsBrokerages.DataSource = dset.Tables["Brokerage"];

            bsClients = new BindingSource(bsBrokerages, "ClientsBrokerage");

            dgvBrokerages.DataSource = bsBrokerages;
            dgvClients.DataSource = bsClients;

            dgvClients.AllowUserToAddRows = false;
            dgvClients.AllowUserToDeleteRows = true;

            sqlCommandBuilder.GetUpdateCommand();
            sqlCommandBuilder.GetInsertCommand();
            sqlCommandBuilder.GetDeleteCommand();
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            try
            {
                if (dgvClients.AllowUserToAddRows)
                {
                    dgvClients.AllowUserToAddRows = false;
                    dataAdapterClients.Update(dset, "Clients");

                    MessageBox.Show("Data added successfully.");
                }
                else
                {
                    dgvClients.AllowUserToAddRows = true;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error adding to database: " + ex.Message);
            }

        }

        private void buttonUpdate_Click(object sender, EventArgs e)
        {
            try
            {
                dataAdapterClients.Update(dset, "Clients");
                dset.Tables["Clients"].Clear();
                dataAdapterClients.Fill(dset, "Clients");

                MessageBox.Show("Table updated successfully.");
            }

            catch (Exception ex)
            {
                MessageBox.Show("Error updating database: " + ex.Message);
            }

        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            try
            {
                if (dgvClients.SelectedRows.Count > 0)
                {
                    int rowIndex = dgvClients.SelectedRows[0].Index;
                    dgvClients.Rows.RemoveAt(rowIndex);
                    dataAdapterClients.Update(dset, "Clients");
                    MessageBox.Show("Data deleted successfully.");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error deleting from database: " + ex.Message);
            }

        }
    }
}
