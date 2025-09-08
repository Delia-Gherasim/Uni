using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;

namespace lab1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string conString = "Data Source=DESKTOP-G5O4MNS\\SQLEXPRESS;" + "Initial Catalog=Concerts; Integrated Security=true;";
            SqlConnection con = new SqlConnection(conString);
            con.Open();

            string strConcerts = "SELECT * FROM Concert";
            SqlCommand cmd = new SqlCommand(strConcerts, con);
            using (SqlDataReader reader = cmd.ExecuteReader())
            {
                while (reader.Read())
                {
                    Console.WriteLine("{0}, {1}", reader[0], reader[1]);
                }
            }
            con.Close();

            SqlDataAdapter daConcerts=new SqlDataAdapter(strConcerts, con);
            DataSet ds = new DataSet();

            con.Open();
            daConcerts.Fill(ds, "Concerts");
            foreach(DataRow pRow in ds.Tables["Concerts"].Rows)
            {
                Console.WriteLine("{0}, {1}", pRow["concertId"], pRow["date"]);
            }
        }
    }
}
