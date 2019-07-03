<%@ Page  Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="web2.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Welcome to Calculator</title>
</head>
<body>
    <p align="center" >Calculator</p>
    <form id="form1" runat="server">
        <div style="margin-left: 720px">
            <asp:TextBox ID="txt_display" runat="server" OnTextChanged="TextBox1_TextChanged" Height="43px" style="text-align: right" Width="235px"></asp:TextBox>
            <asp:Button ID="btn_ON" runat="server" OnClick="btnON_Click" Text="ON" />
        </div>
    <p style="margin-left: 720px">
        <asp:Button ID="btn_1" runat="server" OnClick="btn1_Click" Text="1" Height="41px" style="text-align: center" Width="51px" AccessKey ="1"/>
        <asp:Button ID="btn_2" runat="server" OnClick="btn2_Click" Text="2" Height="41px" Width="49px" />
            <asp:Button ID="btn_3" runat="server" Text="3" OnClick="btn3_Click" Height="41px" Width="52px" />
            <asp:Button ID="btn_plus" runat="server" Text="+" OnClick="btnplus_Click" Height="41px" Width="72px" />
        </p>
        <p style="text-align: left; margin-left: 720px">
            <asp:Button ID="btn_4" runat="server" Text="4" Height="36px" Width="50px" OnClick="btn4_Click" />
            <asp:Button ID="btn_5" runat="server" Text="5" Height="36px" Width="49px" OnClick="btn5_Click" />
            <asp:Button ID="btn_6" runat="server" Text="6" Height="37px" Width="54px" OnClick="btn6_Click" />
            <asp:Button ID="btn_minus" runat="server" Text="-" OnClick="btnminus_Click" Height="38px" Width="73px" />
        </p>
        <p style="margin-left: 720px">
            <asp:Button ID="btn_7" runat="server" Height="36px" Text="7" Width="51px" OnClick="btn7_Click" />
            <asp:Button ID="btn_8" runat="server" Height="36px" Text="8" Width="50px" OnClick="btn8_Click" />
            <asp:Button ID="btn_9" runat="server" Height="36px" Text="9" Width="53px" OnClick="btn9_Click" />
            <asp:Button ID="btn_mul" runat="server" Height="36px" Text="x" Width="74px" OnClick="btnmul_Click"/>
        </p>
        <p style="margin-left: 721px">
            <asp:Button ID="btn_decimal" runat="server" Height="38px" Text="." Width="53px" OnClick="btndecimal_Click" />
            <asp:Button ID="btn_0" runat="server" Height="38px" Text="0" Width="52px" OnClick="btn0_Click" />
            <asp:Button ID="btnsolve" runat="server" OnClick="btnsolve_Click" Text="=" Height="37px" Width="49px" />
            <asp:Button ID="btn_div" runat="server" Height="37px" Text="÷" Width="75px" OnClick="btndiv_Click"/>         
        </p>
        <p>
            <asp:TextBox ID="txt_x" runat="server"  Height="43px" style="text-align: right" Width="235px"></asp:TextBox>
            <asp:TextBox ID="txt_y" runat="server" OnTextChanged="TextBox1_TextChanged" Height="43px" style="text-align: right" Width="235px"></asp:TextBox>
            <asp:TextBox ID="txt_operation" runat="server" OnTextChanged="TextBox1_TextChanged" Height="43px" style="text-align: right" Width="235px"></asp:TextBox>
        </p>
        <p>
            &nbsp;</p>
        <p>
            &nbsp;</p>
        <p>
            &nbsp;</p>
        <p>
            &nbsp;&nbsp;</p>
        <p>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        </p>
    </form>
    </body>
</html>
