<%@ page import="controller.DatabaseAccess" %><%--
  Created by IntelliJ IDEA.
  User: 40723
  Date: 5/24/2024
  Time: 2:47 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<% session = request.getSession(false);
    if (session != null) {
        session.invalidate();
    }
    response.sendRedirect(request.getContextPath() + "/LoginPage.jsp");
    DatabaseAccess databaseAccess=new DatabaseAccess();
    databaseAccess.setLoggedInUserId(-1);
%>
<html>
<head>
    <title>Log Out</title>
</head>
<body>
</body>
</html>
