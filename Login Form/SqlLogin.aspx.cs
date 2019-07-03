using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using MySql;
using MySql.Data.MySqlClient;

namespace Web_databasesql.Login_Form
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        MySqlConnection dt = new MySqlConnection();
        String str;
        protected void Page_Load(object sender, EventArgs e)
        {
            ConnectSql();
        }
        private void ConnectSql()
        {
            string sql = @"Server = localhost;Database = mydatabase;Uid = root;Pwd = 'jettin1997';";
            using (MySqlConnection db = new MySqlConnection(sql))
            {
                db.Open();
                Response.Write("Connected");
            }
        }
    
        protected void getUserID(string ID)
        {
            str += "Select * from users where ";
            if(ID != "")
            {
                str += " UserID ";
            }
        }
    }
}