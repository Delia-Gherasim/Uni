package controller;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import model.User;

import java.io.IOException;

@WebServlet(name = "LoginController", value = "/LoginController")
public class LoginController extends HttpServlet {
    public LoginController() {
        super();
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = request.getParameter("username");
        String password = request.getParameter("password");

        DatabaseAccess authenticator = new DatabaseAccess();
        String result = authenticator.authenticate(username, password);

        if (result.equals("success")) {
            System.out.println("LOGIN SUCCESS");
            User user = new User( username, password, authenticator.getLoggedInUserId());
            HttpSession session = request.getSession();
            session.setAttribute("user", user);

            response.sendRedirect(request.getContextPath() + "/PostsController?action=myPosts");
        } else {
            response.sendRedirect(request.getContextPath() + "/InvalidLogin.html");
        }
    }
}
