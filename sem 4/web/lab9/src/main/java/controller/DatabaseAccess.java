package controller;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import model.Post;

public class DatabaseAccess {
    private Statement statement;
    private Connection connection;

    public int getLoggedInUserId() {
        return LoggedInUserId;
    }

    public void setLoggedInUserId(int loggedInUserId) {
        LoggedInUserId = loggedInUserId;
    }

    private int LoggedInUserId;

    public DatabaseAccess() {
        connect();
    }

    public void connect() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/webLab9", "root", "root");
            statement = connection.createStatement();
        } catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
    private int getAuthenticateId(String name, String password) {
        ResultSet rs;
        int userId = -1;
        try {
            rs = statement.executeQuery("SELECT userId FROM Users WHERE userName='" + name + "' AND password='" + password + "'");
            if (rs.next()) {
                userId = rs.getInt("userId");
            }
            rs.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return userId;
    }

    public String authenticate(String name, String password){
        String result = "error";
        this.LoggedInUserId=getAuthenticateId(name, password);
        if (this.LoggedInUserId != -1){
            result = "success";
        }
        return result;
    }

    public List<Post> getFirstNPosts(int n) {
        List<Post> posts = new ArrayList<>();
        ResultSet rs;

        try {
            String query = "SELECT * FROM Posts INNER JOIN Users ON Posts.userId = Users.userId ORDER BY Posts.votes DESC LIMIT ?";
            PreparedStatement ps = connection.prepareStatement(query);
            ps.setInt(1, n);
            rs = ps.executeQuery();

            while (rs.next()) {
                int postId = rs.getInt("postId");
                String photo = rs.getString("photo");
                int nrOfVotes = rs.getInt("votes");
                String userName = rs.getString("userName");

                Post post = new Post(postId, nrOfVotes, photo, userName);
                posts.add(post);
            }
            rs.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return posts;
    }
    public void addPost(int userId, String photo) {
        try {
            String query = "INSERT INTO Posts (photo, votes, userId) VALUES (?, 0, ?)";
            PreparedStatement ps = connection.prepareStatement(query);
            ps.setString(1, photo);
            ps.setInt(2, userId);
            ps.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void incrementPostLikes(int postId, int userId) {
        try {
            String query = "UPDATE Posts SET votes = votes + 1 WHERE postId = ? and userId <> ?";
            PreparedStatement ps = connection.prepareStatement(query);
            ps.setInt(1, postId);
            ps.setInt(2, userId);
            ps.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
