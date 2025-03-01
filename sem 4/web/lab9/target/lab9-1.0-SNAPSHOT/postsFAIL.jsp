<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="model.Post" %>
<%@ page import="java.util.List" %>
<%@ page import="model.User" %>
<%
  User user = (User) session.getAttribute("user");
  if (user == null) {
    response.sendRedirect("LoginPage.jsp");
    return;
  }
%>
<!DOCTYPE html>
<html>
<head>
  <title>Posts</title>
</head>
<body>
<h2>Posts</h2>

<div class="topbar">
  <a href="LogoutController">Log Out</a>
</div>

<form action="PostsController" method="post">
  <input type="hidden" name="action" value="addPost"/>
  <label for="photo">Photo URL:</label>
  <input type="text" id="photo" name="photo"/>
  <input type="submit" value="Add Post"/>
</form>

<form action="PostsController" method="post">
  <input type="hidden" name="action" value="topPosts"/>
  <label for="numberOfPosts">Number of top posts to display:</label>
  <input type="text" id="numberOfPosts" name="numberOfPosts"/>
  <input type="submit" value="Show Top Posts"/>
</form>

<h3>All Posts</h3>
<ul>
  <%
    List<Post> posts = (List<Post>) request.getAttribute("posts");
    if (posts != null) {
      for (Post post : posts) {
  %>
  <li>
    <img src="<%= post.getPhotoPath() %>" alt="Post Image" style="width:100px;height:100px;"/><br>
    Posted by: <%= post.getUserName() %><br>
    Votes: <%= post.getNrOfVotes() %><br>
    <form action="PostsController" method="post">
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
