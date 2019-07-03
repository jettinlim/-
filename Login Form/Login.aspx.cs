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
        MySql.Data.MySqlClient.MySqlCommand cmd;
        MySql.Data.MySqlClient.MySqlDataReader reader;
        protected void Page_Load_Login(object sender, EventArgs e)
        {
            if(!Page.IsPostBack)
            {
                
            }
            
        }
       
        public void btnLogin_Click(object sender, EventArgs e)
        {
            string sql = @"Server = localhost;Database = mydatabase;Uid = root;Pwd = 'jettin1997';";
            MySql.Data.MySqlClient.MySqlConnection connection = new MySql.Data.MySqlClient.MySqlConnection(sql);
            connection.Open();
           
            string str = "Select * from users where UserID = '" + txtUsername.Text.ToString() + "' and Password = '" + txtPassword.Text.ToString() + "'";
            if (txtUsername.Text.ToString() == "")
            {
                Response.Write("Please enter username");
            }

            if (txtPassword.Text.ToString() == "")
            {
                Response.Write("\nPlease enter password");
            }

            cmd = new MySql.Data.MySqlClient.MySqlCommand(str, connection);
            reader = cmd.ExecuteReader();
           if(txtUsername.Text.ToString() != "" && txtPassword.Text.ToString() != "")
            {
                if (reader.HasRows)
                {
                    Server.Transfer("calculator.aspx");          
                }

                else
                {
                    Response.Write("Wrong username or password");
                    txtPassword.Text = null;
                }
                //connection.Close();
            }
        }
               



    }

}