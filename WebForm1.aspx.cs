using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using MySql;
using MySql.Data.MySqlClient;

namespace Web_databasesql
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if(!IsPostBack)
            {
                //CheckMysqlConnection();
            }
            
        }
        private void CheckMysqlConnection()
        {
            string ConnectionString = @"Server = localhost;Database = mydatabase;Uid = root;Pwd = 'jettin1997';";
            using (MySqlConnection connect = new MySqlConnection(ConnectionString))
            {
                try
                {
                    connect.Open();
                    Response.Write("MySql connection successful");
                }
                catch
                {
                    Response.Write("MySql connection fail");

                }

            }
        }
    }
    
}