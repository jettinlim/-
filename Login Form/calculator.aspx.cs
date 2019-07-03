using System;
using System.Data;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using MySql;
using MySql.Data.MySqlClient;

namespace web2
{

    public partial class WebForm1 : System.Web.UI.Page
    {
        string operation;
        bool empty,equal;
        double x, y, result;
        string status;
        protected void Page_Load(object sender, EventArgs e)
        {
            object y = ViewState["equal"];
            if (y != null)
            {
                equal = (bool)y;
            }

            object o = ViewState["status"];
            if (o != null)
            {
                status = (string)o;
            }

            object i = ViewState["empty"];
            if (i != null)
            {
                empty = (bool)i;
            }

            if (empty == true)
            {
                empty = true;
                Response.Write("empty true");
            }

            else
            {
                empty = false;
                Response.Write("empty false");
            }

        }

        protected void MysqlConnect()
        {
            string ConnectionString = @"Server = localhost;Database = mydatabase;Uid = root;Pwd = 'jettin1997';";
            using (MySqlConnection connect = new MySqlConnection(ConnectionString))
            {
                try
                {
                    connect.Open();
                }
                catch
                {
                    Response.Write("MySql connection fail");
                }

            }
        }

        protected void CheckBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        protected void btn1_Click(object sender, EventArgs e)
        {
            if(status == "ON")
            {
                if (empty == true || txt_display.Text.ToString() == "0")
                {
                    txt_display.Text = null;
                }
                txt_display.Text += 1;
                empty = false;
                ViewState["empty"] = empty;
            }
            
        }

        protected void btn2_Click(object sender, EventArgs e)
        {
            if (status == "ON")
            {
                if (empty == true || txt_display.Text.ToString() == "0")
                {
                    txt_display.Text = null;
                }

                txt_display.Text += 2;
                empty = false;
                ViewState["empty"] = empty;
            }
                
        }

        protected void btn3_Click(object sender, EventArgs e)
        {
            if (status == "ON")
            {
                if (empty == true || txt_display.Text.ToString() == "0")
                {
                    txt_display.Text = null;
                }

                txt_display.Text += 3;
                empty = false;
                ViewState["empty"] = empty;
            }
        }

        protected void btn4_Click(object sender, EventArgs e)
        {
            if (status == "ON")
            {
                if (empty == true || txt_display.Text.ToString() == "0")
                {
                    txt_display.Text = null;
                }

                txt_display.Text += 4;
                empty = false;
                ViewState["empty"] = empty;
            }
        }

        protected void btn5_Click(object sender, EventArgs e)
        {
            if (status == "ON")
            {
                if (empty == true || txt_display.Text.ToString() == "0")
                {
                    txt_display.Text = null;
                }

                txt_display.Text += 5;
                empty = false;
                ViewState["empty"] = empty;
            }
        }

        protected void btn6_Click(object sender, EventArgs e)
        {
            if (status == "ON")
            {
                if (empty == true || txt_display.Text.ToString() == "0")
                {
                    txt_display.Text = null;
                }

                txt_display.Text += 6;
                empty = false;
                ViewState["empty"] = empty;
            }
        }

        protected void btn7_Click(object sender, EventArgs e)
        {
            if (status == "ON")
            {
                if (empty == true || txt_display.Text.ToString() == "0")
                {
                    txt_display.Text = null;
                }

                txt_display.Text += 7;
                empty = false;
                ViewState["empty"] = empty;
            }
        }

        protected void btn8_Click(object sender, EventArgs e)
        {
            if (status == "ON")
            {
                if (empty == true || txt_display.Text.ToString() == "0")
                {
                    txt_display.Text = null;
                }

                txt_display.Text += 8;
                empty = false;
                ViewState["empty"] = empty;
            }
        }

        protected void btn9_Click(object sender, EventArgs e)
        {
            if (status == "ON")
            {
                if (empty == true || txt_display.Text.ToString() == "0")
                {
                    txt_display.Text = null;
                }

                txt_display.Text += 9;
                empty = false;
                ViewState["empty"] = empty;
            }
        }

        protected void btn0_Click(object sender, EventArgs e)
        {
            if (status == "ON")
            {
                if (empty == true || txt_display.Text.ToString() == "0")
                {
                    txt_display.Text = null;
                }

                txt_display.Text += 0;
                empty = false;
                ViewState["empty"] = empty;
            }
        }

        protected void btnplus_Click(object sender, EventArgs e)
        {       
            if(empty == false)
            {
                if(equal == true)
                {
                    x = Convert.ToDouble(txt_display.Text.ToString());
                    txt_x.Text = x.ToString();
                }
                else
                {
                    if (txt_x.Text.ToString() == "")
                    {
                        x = Convert.ToDouble(txt_display.Text.ToString());
                        txt_x.Text = x.ToString();
                    }

                    else
                    {
                        y = Convert.ToDouble(txt_display.Text.ToString());
                        txt_y.Text = y.ToString();
                    }
                }

                if (txt_x.Text.ToString() != "" && txt_y.Text.ToString() != "")
                {
                    x = Convert.ToDouble(txt_x.Text.ToString());
                    if (txt_operation.Text.ToString() == "plus")
                    {
                        result = x + y;
                    }
                    if (txt_operation.Text.ToString() == "minus")
                    {
                        result = x - y;
                    }
                    if (txt_operation.Text.ToString() == "multiple")
                    {
                        result = x * y;
                    }
                    if (txt_operation.Text.ToString() == "devide")
                    {
                        result = x / y;
                    }

                    txt_display.Text = result.ToString();
                    x = result;
                    txt_x.Text = result.ToString();
                }
                operation = "plus";
                txt_operation.Text = operation;

                empty = true;
                equal = false;
                if (empty == true)
                {
                    Response.Write("empty true");

                }
                ViewState["empty"] = true;
                ViewState["equal"] = equal;
            }
            
        }

        protected void btnminus_Click(object sender, EventArgs e)
        {
            if(empty == false)
            {
                if (equal == true)
                {
                    x = Convert.ToDouble(txt_display.Text.ToString());
                    txt_x.Text = x.ToString();
                }
                else
                {
                    if (txt_x.Text.ToString() == "")
                    {
                        x = Convert.ToDouble(txt_display.Text.ToString());
                        txt_x.Text = x.ToString();
                    }

                    else
                    {
                        y = Convert.ToDouble(txt_display.Text.ToString());
                        txt_y.Text = y.ToString();
                    }
                }

                if (txt_x.Text.ToString() != "" && txt_y.Text.ToString() != "")
                {
                    x = Convert.ToDouble(txt_x.Text.ToString());
                    if (txt_operation.Text.ToString() == "plus")
                    {
                        result = x + y;
                    }
                    if (txt_operation.Text.ToString() == "minus")
                    {
                        result = x - y;
                    }
                    if (txt_operation.Text.ToString() == "multiple")
                    {
                        result = x * y;
                    }
                    if (txt_operation.Text.ToString() == "devide")
                    {
                        result = x / y;
                    }

                    txt_display.Text = result.ToString();
                    x = result;
                    txt_x.Text = result.ToString();
                }
                operation = "minus";
                txt_operation.Text = operation;

                empty = true;
                if (empty == true)
                {
                    Response.Write("empty true");

                }
                ViewState["empty"] = true;
                equal = false;
                ViewState["equal"] = equal;
            }
            
        }

        protected void btnmul_Click(object sender, EventArgs e)
        {
            if(empty == false)
            {
                if (equal == true)
                {
                    x = Convert.ToDouble(txt_display.Text.ToString());
                    txt_x.Text = x.ToString();
                }
                else
                {
                    if (txt_x.Text.ToString() == "")
                    {
                        x = Convert.ToDouble(txt_display.Text.ToString());
                        txt_x.Text = x.ToString();
                    }

                    else
                    {
                        y = Convert.ToDouble(txt_display.Text.ToString());
                        txt_y.Text = y.ToString();
                    }
                }

                if (txt_x.Text.ToString() != "" && txt_y.Text.ToString() != "")
                {
                    x = Convert.ToDouble(txt_x.Text.ToString());
                    if (txt_operation.Text.ToString() == "plus")
                    {
                        result = x + y;
                    }
                    if (txt_operation.Text.ToString() == "minus")
                    {
                        result = x - y;
                    }
                    if (txt_operation.Text.ToString() == "multiple")
                    {
                        result = x * y;
                    }
                    if (txt_operation.Text.ToString() == "devide")
                    {
                        result = x / y;
                    }

                    txt_display.Text = result.ToString();
                    x = result;
                    txt_x.Text = result.ToString();
                }
                operation = "multiple";
                txt_operation.Text = operation;

                empty = true;
                if (empty == true)
                {
                    Response.Write("empty true");

                }
                ViewState["empty"] = true;
                equal = false;
                ViewState["equal"] = equal;
            }
            
        }

        protected void btndiv_Click(object sender, EventArgs e)
        {
            if(empty == false)
            {
                if (equal == true)
                {
                    x = Convert.ToDouble(txt_display.Text.ToString());
                    txt_x.Text = x.ToString();
                }
                else
                {
                    if (txt_x.Text.ToString() == "")
                    {
                        x = Convert.ToDouble(txt_display.Text.ToString());
                        txt_x.Text = x.ToString();
                    }

                    else
                    {
                        y = Convert.ToDouble(txt_display.Text.ToString());
                        txt_y.Text = y.ToString();
                    }
                }

                if (txt_x.Text.ToString() != "" && txt_y.Text.ToString() != "")
                {
                    x = Convert.ToDouble(txt_x.Text.ToString());
                    if (txt_operation.Text.ToString() == "plus")
                    {
                        result = x + y;
                    }
                    if (txt_operation.Text.ToString() == "minus")
                    {
                        result = x - y;
                    }
                    if (txt_operation.Text.ToString() == "multiple")
                    {
                        result = x * y;
                    }
                    if (txt_operation.Text.ToString() == "devide")
                    {
                        result = x / y;
                    }

                    txt_display.Text = result.ToString();
                    x = result;
                    txt_x.Text = result.ToString();
                }
                operation = "devide";
                txt_operation.Text = operation;

                empty = true;
                if (empty == true)
                {
                    Response.Write("empty true");

                }
                ViewState["empty"] = true;
                equal = false;
                ViewState["equal"] = equal;
            }
            
        }

        protected void btnON_Click(object sender, EventArgs e)
        {
            status = "ON";
            x = 0;
            y = 0;
            result = 0;
            operation = "";

            txt_display.Text = "0";
            txt_x.Text = null;
            txt_y.Text = null;
            txt_operation.Text = null;
            ViewState["status"] = status;

        }

        protected void btndecimal_Click(object sender, EventArgs e)
        {
            txt_display.Text += ".";
        }

        protected void btnsolve_Click(object sender, EventArgs e)
        {
            if(equal == false)
            {
                x = Convert.ToDouble(txt_x.Text.ToString());
                y = Convert.ToDouble(txt_display.Text.ToString());
                if (txt_operation.Text.ToString() == "plus")
                {
                    result = x + y;
                }
                if (txt_operation.Text.ToString() == "minus")
                {
                    result = x - y;
                }
                if (txt_operation.Text.ToString() == "multiple")
                {
                    result = x * y;
                }
                if (txt_operation.Text.ToString() == "devide")
                {
                    result = x / y;
                }

                txt_display.Text = result.ToString();
                x = Convert.ToDouble(txt_x.Text.ToString());
                txt_x.Text = x.ToString();
                y = 0;
                txt_y.Text = null;
                equal = true;
                ViewState["equal"] = equal;
            }          
        }

        protected void TextBox1_TextChanged(object sender, EventArgs e)
        {


        }

    }

}