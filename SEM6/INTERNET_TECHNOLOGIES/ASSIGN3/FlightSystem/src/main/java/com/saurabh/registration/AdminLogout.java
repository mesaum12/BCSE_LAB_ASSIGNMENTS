package com.saurabh.registration;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet("/AdminLogout")
public class AdminLogout extends HttpServlet {
private static final long serialVersionUID = 1L;
       
    
    public AdminLogout() {
        super();
        // TODO Auto-generated constructor stub
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		System.out.println("admin decided to log out-----------");
		HttpSession session=request.getSession();
		System.out.println("Current user name:");
		System.out.println(session.getAttribute("admin_name"));
		
	    System.out.println("Current user name after invalidation:");
		System.out.println(session.getAttribute("admin_name"));
		session.setAttribute("logoutAdmin", "true");
//		RequestDispatcher rd=request.getRequestDispatcher("test.html");
		RequestDispatcher rd=request.getRequestDispatcher("test.jsp");
		rd.forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
