<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Web_databasesql.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Documentation</title>
</head>
<body>
    <h1 align="center">
        <font size="20" color="blue">Login</font>
    </h1>
    <br>
    <form id="Login_Form" runat="server">
        <div align="center">
            <font font size="4" > Username : </font>
        <asp:TextBox ID="txtUsername" runat="server" CssClass="form-control" Width="150px" AutoCompleteType ="disabled"></asp:TextBox>
            </div>
        <br />
        <div align="center">
            <font font size="4" > Password : </font>
        <asp:TextBox ID="txtPassword" runat="server" CssClass="form-control" Width="150px" type ="password" ></asp:TextBox>
            </div>
        <br />
        <div align="center">            
        <asp:Button ID="btnLogin" runat="server" OnClick="btnLogin_Click" Text="Login"  ></asp:Button>
            </div>
    </form>
</body>
</html>
