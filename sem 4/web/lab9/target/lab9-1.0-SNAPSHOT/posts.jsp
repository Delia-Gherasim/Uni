<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="model.Post" %>
<%@ page import="java.util.List" %>
<%@ page import="model.User" %>
<%@ page import="controller.DatabaseAccess" %>
<!DOCTYPE html>
<html>
<head>
    <title>Posts</title>
    <style>
        .topbar {
            background-color: #333;
            color: #fff;
            padding: 10px;
            text-align: right;
        }

        .topbar a {
            color: #fff;
            padding: 5px 10px;
            border-radius: 3px;
        }

        .topbar a:hover {
            background-color: #555;
        }

        form {
            margin-bottom: 20px;
        }

        form input[type="text"],
        form input[type="submit"] {
            padding: 10px;
            margin-right: 10px;
            border: 1px solid #ccc;
            border-radius: 3px;
            box-sizing: border-box;
        }

        ul {
            list-style: none;
            padding: 0;
        }

        li {
            background-color: #fff;
            border: 1px solid #ccc;
            border-radius: 3px;
            padding: 10px;
            margin-bottom: 10px;
        }

        form.like-form {
            display: inline;
        }

        form.like-form input[type="submit"] {
            background-color: #007bff;
            color: #fff;
            border: none;
            padding: 5px 10px;
            border-radius: 3px;
            cursor: pointer;
        }

        form.like-form input[type="submit"]:hover {
            background-color: #0056b3;
        }
    </style>
</head>
<body>
<div class="topbar">
    <h3>All Posts</h3>
<%--    <a href="LogoutController">Log Out</a>--%>
</div>

<form action="posts.jsp" method="post">
    <input type="hidden" name="action" value="addPost"/>
    <label for="photo">Photo URL:</label>
    <input type="text" id="photo" name="photo"/>
    <input type="submit" value="Add Post"/>
</form>

<form action="posts.jsp" method="post">
    <input type="hidden" name="action" value="topPosts"/>
    <label for="numberOfPosts">Number of top posts to display:</label>
    <input type="text" id="numberOfPosts" name="numberOfPosts"/>
    <input type="submit" value="Show Top Posts"/>
</form>
<ul>
    <%
        String action = request.getParameter("action");
        DatabaseAccess databaseAccess = new DatabaseAccess();
        session = request.getSession();
        User user = (User) session.getAttribute("user");

        if (action != null && user != null) {
            if ("addPost".equals(action)) {
                String photo = request.getParameter("photo");
                databaseAccess.addPost(user.getId(), photo);
            } else if ("likePost".equals(action)) {
                int postId = Integer.parseInt(request.getParameter("postId"));
                databaseAccess.incrementPostLikes(postId, user.getId());
            } else if ("topPosts".equals(action)) {
                int n = Integer.parseInt(request.getParameter("numberOfPosts"));
                List<Post> topPosts = databaseAccess.getFirstNPosts(n);
                request.setAttribute("posts", topPosts);
            }
        }

        List<Post> posts = (List<Post>) request.getAttribute("posts");
        if (posts != null) {
            for (Post post : posts) {
    %>
    <li>
        <img src="<%= post.getPhotoPath() %>" alt="Post Image"/><br>
        Posted by: <%= post.getUserName() %><br>
        Votes: <%= post.getNrOfVotes() %><br>
        <form action="posts.jsp" method="post" class="like-form">
            <input type="hidden" name="action" value="likePost"/>
            <input type="hidden" name="postId" value="<%= post.getId() %>"/>
            <input type="submit" value="Like"/>
        </form>
    </li>
    <%
            }
        }
    %>
</ul>

</body>
</html>
