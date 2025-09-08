<%--<form action="LoginController" method="post">--%>
<%--    Enter username : <input type="text" name="username"> <br>--%>
<%--    Enter password : <input type="password" name="password"> <br>--%>
<%--    <input type="submit" value="Login"/>--%>
<%--</form>--%>
<%@ page import="controller.DatabaseAccess" %>
<%@ page import="model.User" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Log In</title>
</head>
<style>
    body {
        display: flex;
        justify-content: center;
        align-items: center;
        height: 100vh;
    }

    .login-container {
        background-color: #fff;
        border-radius: 5px;
        padding: 20px;
        border-color: #555555;
        width: 300px;
    }

    input[type="text"],
    input[type="password"],
    input[type="submit"] {
        width: 100%;
        padding: 10px;
        margin-bottom: 10px;
        border: 1px solid #ccc;
        border-radius: 3px;
        box-sizing: border-box;
    }

    input[type="submit"] {
        background-color: #4caf50;
        color: #fff;
        cursor: pointer;
    }

    input[type="submit"]:hover {
        background-color: #45a049;
    }

    h2 {
        color: #333;
    }

    a {
        text-decoration: none;
        color: #007bff;
    }

    a:hover {
        text-decoration: underline;
    }
</style>
</head>
<body>
<div class="login-container">
    <form action="LoginPage.jsp" method="post">
        <label for="username">Enter username:</label><br>
        <input type="text" id="username" name="username"><br>
        <label for="password">Enter password:</label><br>
        <input type="password" id="password" name="password"><br>
        <input type="submit" value="Login">
    </form>
</div>
<%
    String username = request.getParameter("username");
    String password = request.getParameter("password");

    if (username != null && password != null) {
        DatabaseAccess databaseAccess = new DatabaseAccess();
        String result = databaseAccess.authenticate(username, password);

        if (result.equals("success")) {
            System.out.println("LOGIN SUCCESS");
            int id= databaseAccess.getLoggedInUserId();
            User user = new User(username, password, id);
            session = request.getSession();
            session.setAttribute("user", user);
%>

<h2>Login Successful</h2>
<p>Welcome, <%= user.getName() %>!</p>
<a href="posts.jsp">Go to Posts</a>
<%
} else {
%>
<h2>Invalid Login</h2>
<a href="LoginPage.jsp">Try Again</a>
<%
        }
    }
%>

</body>
</html>
