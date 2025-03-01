<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>Only Votes</title>
</head>
<style>
    .topbar{
        background-color: #EA7FE4;
        margin-top: 0;
        width: 100%;
        display: flex;
        justify-content: space-around;
        align-items: center;   }
</style>
<body>
    <div class="topbar">
        <h3>Hello, <% getUser()%>!</h3>
        <h3><button class="button">Log In</button></h3>
        <!-- <p><%= new java.util.Date() %></p> -->
        
    </div>
    <div class="mainContent">
        
    </div>

</body>
</html>
<%getUser(){

}%>