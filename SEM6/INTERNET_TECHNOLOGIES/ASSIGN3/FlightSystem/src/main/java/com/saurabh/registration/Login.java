// user login servlet
package com.saurabh.registration;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.saurabh.DatabaseConnection.MyDatabase;

@WebServlet("/login")
public class Login extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	
		RequestDispatcher dispatcher=null;
		HttpSession session=request.getSession();
		String uname=request.getParameter("username");
		String password=request.getParameter("password");
//		Connection conn=null;
		
		MyDatabase mydata = (MyDatabase) getServletContext().getAttribute("DatabaseSSLFalse");  
        Connection conn = mydata.getCon();  
        if (conn != null) {  
            System.out.println("Database is connected");  
        } else {  
            System.out.println("Database is not connected");  
        }  
		
		// JDBC driver name and database URL 
//	    static final String JDBC_DRIVER="com.mysql.jdbc.Driver";   
//	    final String DB_URL="jdbc:mysql://localhost:3306/FlightSystem?useSSL=false";
//	    //  Database credentials 
//	    final String USER = "root"; 
//	    final String PASS = "9406";
		try{ 
	         // Register JDBC driver 
	        // Class.forName("com.mysql.jdbc.Driver"); 
	 
	         // Open a connection 
	         //conn = DriverManager.getConnection(DB_URL, USER, PASS); 
	         String sql="select * from users where uname=? and upwd=?";
	         
	         PreparedStatement pst=conn.prepareStatement(sql);
	         
	         pst.setString(1, uname);
	         pst.setString(2, password);
             
	         ResultSet rs=pst.executeQuery();
	         if(rs.next())
	         {
	        	session.setAttribute("name",rs.getString("uname"));
//	        	dispatcher =request.getRequestDispatcher("index.jsp");
	        	dispatcher =request.getRequestDispatcher("index.jsp");
	         } 
	         else
	         {
	        	 request.setAttribute("status", "failed");
	        	 dispatcher =request.getRequestDispatcher("login.jsp");
	         }
	         dispatcher.forward(request,response);
	         
	         
	    }
		catch(Exception e)
		{
			e.printStackTrace();
		}
	
	
	}

}
