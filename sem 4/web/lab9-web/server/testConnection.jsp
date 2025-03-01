<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="java.sql.Connection" %>
<%@ page import="java.sql.DriverManager" %>
<%@ page import="java.sql.SQLException" %>

<!DOCTYPE html>
<html>
<head>
    <title>Test Connection to SSMS</title>
</head>
<body>

<%
    String message = "";
    Connection connection = null;

    try {
        // Attempt to establish a connection
        Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
        // connection = DriverManager.getConnection("jdbc:sqlserver://DESKTOP-G5O4MNS\\SQLEXPRESS:1433;databaseName=webfacebook3", "", "");
        connection = DriverManager.getConnection("jdbc:sqlserver://DESKTOP-G5O4MNS\\SQLEXPRESS:1433;databaseName=webfacebook3;trustServerCertificate=true","dell","123456789abc");

        // If connection is successful, set success message
        message = "Connection to SSMS server successful!";
    } catch (Exception e) {
        // If connection fails, set error message
        message = "Error connecting to SSMS server: " + e.getMessage();
    } finally {
        // Close the connection
        if (connection != null) {
            try {
                connection.close();
            } catch (SQLException e) {
                // Ignore
            }
        }
    }
%>

<h2><%= message %></h2>

</body>
</html>
