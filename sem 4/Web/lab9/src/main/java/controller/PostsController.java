package controller;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import model.Post;
import model.User;

import java.io.IOException;
import java.util.List;

@WebServlet(name = "PostsController", value = "/PostsController")
public class PostsController extends HttpServlet {
    public PostsController() {
        super();
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        DatabaseAccess databaseAccess = new DatabaseAccess();
        List<Post> products = databaseAccess.getFirstNPosts(3);
        request.setAttribute("products", products);
        request.getRequestDispatcher("/postsFAIL.jsp").forward(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        User user = (User) session.getAttribute("user");

        if (user == null) {
            response.sendRedirect(request.getContextPath() + "/LoginPage.jsp");
            return;
        }

        String action = request.getParameter("action");
        DatabaseAccess databaseAccess = new DatabaseAccess();

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
            RequestDispatcher rd = request.getRequestDispatcher("/postsFAIL.jsp");
            rd.forward(request, response);
            return;
        }

        response.sendRedirect(request.getContextPath() + "/PostsController");
    }
}
