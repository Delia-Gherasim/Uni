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
        // Load the JDBC driver
        Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");

        // Database connection details
        String dbURL = "jdbc:sqlserver://DESKTOP-G5O4MNS\\SQLEXPRESS:1433;databaseName=webfacebook3;trustServerCertificate=true";
        String user = "\\40723"; // Replace with your username
        String password = null; // Replace with your password

        // Attempt to establish a connection
        connection = DriverManager.getConnection(dbURL, user, password);

        // If connection is successful, set success message
        message = "Connection to SSMS server successful!";
    } catch (ClassNotFoundException e) {
        message = "SQLServerDriver not found: " + e.getMessage();
    } catch (SQLException e) {
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
