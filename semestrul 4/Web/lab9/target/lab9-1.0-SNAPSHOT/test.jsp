<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="java.sql.*" %>

<!DOCTYPE html>
<html>
<head>
    <title>Test</title>
</head>
<body>

<%
    String message = "";
    Connection connection = null;
    String result = "error";
    try {
        Class.forName("com.mysql.cj.jdbc.Driver");
        connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/webLab9", "root", "root");
        Statement statement = connection.createStatement();
        ResultSet rs = statement.executeQuery("SELECT * FROM Users");

        if (rs != null) {
            result = "success";
%>

<h2><%= result %></h2>
<table>
    <tr>
        <th>ID</th>
        <th>Name</th>
        <th>Email</th>
        <th>Password</th>
    </tr>

    <%
        while (rs.next()) {
    %>
    <tr>
        <td><%= rs.getInt("userId") %></td>
        <td><%= rs.getString("userName") %></td>
        <td><%= rs.getString("email") %></td>
        <td><%= rs.getString("password") %></td>
    </tr>
    <%
            }
            rs.close();
        }
    } catch (Exception e) {
        message = "Error connecting to MySQL server: " + e.getMessage();
    %>
    <h2><%= message %></h2>
    <%
        } finally {
            if (connection != null) {
                try {
                    connection.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        }
    %>
</table>

</body>
</html>
