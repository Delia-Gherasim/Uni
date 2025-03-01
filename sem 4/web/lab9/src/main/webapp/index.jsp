<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>Facebook3</title>
</head>
<style>
    .topbar {
        background-color: #333;
        color: #fff;
        padding: 10px;
        text-align: right;
    }
    .topbar a {
        color: #fff;
        text-decoration: none;
        padding: 5px 10px;
        border-radius: 3px;
        transition: background-color 0.3s;
    }

    .topbar a:hover {
        background-color: #555;
    }
</style>
<body>
    <div class="topbar">
        <h3>Hello!</h3>
        <a href="LoginPage.jsp">Log In</a>
        <a href="posts.jsp">See Posts</a>
        <p><%= new java.util.Date() %></p>
    </div>
    <div class="mainContent">

    </div>
</body>
</html>
