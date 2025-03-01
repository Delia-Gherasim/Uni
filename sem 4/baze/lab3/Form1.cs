using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Reflection.Emit;
using System.Windows.Forms;
using System.Xml.Linq;

namespace lab2
{
    public partial class Form1 : Form
    {
        SqlConnection conn;
        SqlDataAdapter daTable1;
        SqlDataAdapter daTable2;
        DataSet dset;
        BindingSource bsTable1;
        BindingSource bsTable2;
        SqlCommandBuilder cmBuilder;
        List<TableConfiguration> tableConfigurations = new List<TableConfiguration>();
        private int currentTableIndex = 0;
        private string table2;


        public Form1()
        {
            InitializeComponent();
            load();
            FillData(tableConfigurations[currentTableIndex]);
        }
        private void load()
        {
            Console.WriteLine("Reading from file: ");

            XDocument xDocument = XDocument.Load("C:/Facultation/sem4/baze/lab2/tables.xml");
            XElement root = xDocument.Element("ConfigFile");
            try
            {
                if (root != null && root.HasElements)
                {
                    foreach (var Elem in root.Elements("Data"))
                    {
                        TableConfiguration config = new TableConfiguration
                        {
                            Connection = (string)Elem.Attribute("Connection"),
                            Table1 = (string)Elem.Attribute("Table1"),
                            Table2 = (string)Elem.Attribute("Table2"),
                            QueryTable1 = (string)Elem.Attribute("Query1"),
                            QueryTable2 = (string)Elem.Attribute("Query2"),
                            ColumnTable1 = (string)Elem.Attribute("Column1"),
                            ColumnTable2 = (string)Elem.Attribute("Column2"),
                            Relation = (string)Elem.Attribute("Relation")
                        };

                        tableConfigurations.Add(config);
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
        }
        private void FillData(TableConfiguration config)
        {
            this.table2 = config.Table2;
            Label1.Text = config.Table1;
            Label2.Text = config.Table2;

            conn = new SqlConnection(config.Connection);

            daTable1 = new SqlDataAdapter(config.QueryTable1, conn);
            daTable2 = new SqlDataAdapter(config.QueryTable2, conn);
            dset = new DataSet();
            daTable1.Fill(dset, config.Table1);
            daTable2.Fill(dset, config.Table2);

            cmBuilder = new SqlCommandBuilder(daTable2);

            dset.Relations.Add(config.Relation, dset.Tables[config.Table1].Columns[config.ColumnTable1], dset.Tables[config.Table2].Columns[config.ColumnTable2]);

            bsTable1 = new BindingSource();
            bsTable1.DataSource = dset.Tables[config.Table1];
            bsTable2 = new BindingSource(bsTable1, config.Relation);

            dataGridView1.DataSource = bsTable1;
            dataGridView2.DataSource = bsTable2;

            dataGridView2.AllowUserToAddRows = false;
            dataGridView2.AllowUserToDeleteRows = true;

            cmBuilder.GetUpdateCommand();
            cmBuilder.GetInsertCommand();
            cmBuilder.GetDeleteCommand();
        }

        //private void button1_Click(object sender, EventArgs e) //ADD BUTTON
        //{
        //    if (dataGridView1.AllowUserToAddRows)
        //    {
        //        dataGridView1.AllowUserToAddRows = false;
        //        daTable1.Update(dset, table1);
        //    }
        //    else
        //    {
        //        dataGridView1.AllowUserToAddRows = true;
        //    }
        //}

        //private void button2_Click(object sender, EventArgs e) //DELETE BUTTON
        //{
        //    if (dataGridView1.SelectedRows.Count > 0)
        //    {
        //        int rowIndex = dataGridView1.SelectedRows[0].Index;
        //        dataGridView1.Rows.RemoveAt(rowIndex);
        //        daTable1.Update(dset, table1);
        //    }
        //}

        //private void button3_Click(object sender, EventArgs e)  // UPDATE BUTTON
        //{
        //    try
        //    {
        //        daTable1.Update(dset, table1);
        //        dset.Tables[table1].Clear();
        //        daTable1.Fill(dset, table1);

        //        MessageBox.Show("Database updated successfully.");
        //    }

        //    catch (Exception ex)
        //    {
        //        MessageBox.Show("Error updating database: " + ex.Message);
        //    }
        //}



        private void button1_Click(object sender, EventArgs e) //ADD BUTTON
        {
            if (dataGridView2.AllowUserToAddRows)
            {
                dataGridView2.AllowUserToAddRows = false;
                daTable2.Update(dset, table2);
            }
            else
            {
                dataGridView2.AllowUserToAddRows = true;
            }
        }

        private void button2_Click(object sender, EventArgs e) //DELETE BUTTON
        {
            if (dataGridView1.SelectedRows.Count > 0)
            {
                int rowIndex = dataGridView2.SelectedRows[0].Index;
                dataGridView2.Rows.RemoveAt(rowIndex);
                daTable2.Update(dset, table2);
            }
        }

        private void button3_Click(object sender, EventArgs e)  // UPDATE BUTTON
        {
            try
            {
                daTable2.Update(dset, table2);
                dset.Tables[table2].Clear();
                daTable2.Fill(dset, table2);

                MessageBox.Show("Database updated successfully.");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error updating database: " + ex.Message);
            }
        }

       

        private void Songs_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e) //switch tables
        {
            if (tableConfigurations.Count > 0)
            {
                currentTableIndex++;
                if (currentTableIndex >= tableConfigurations.Count)
                {
                    currentTableIndex = 0;
                }
                FillData(tableConfigurations[currentTableIndex]);
            }

        }

        private void Label2_Click_1(object sender, EventArgs e)
        {

        }
    }
    public class TableConfiguration
    {
        public string Connection { get; set; }
        public string Table1 { get; set; }
        public string Table2 { get; set; }
        public string QueryTable1 { get; set; }
        public string QueryTable2 { get; set; }
        public string ColumnTable1 { get; set; }
        public string ColumnTable2 { get; set; }
        public string Relation { get; set; }
    }
}
