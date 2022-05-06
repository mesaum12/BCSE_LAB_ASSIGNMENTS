package com.saurabh.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import com.saurabh.model.User;

public class RegistrationDao {
	
	private Connection conn;
	public RegistrationDao(Connection conn)
	{
		this.conn=conn;
	}
	
	// JDBC driver name and database URL 
//    static final String JDBC_DRIVER="com.mysql.jdbc.Driver";   
//    static final String DB_URL="jdbc:mysql://localhost:3306/FlightSystem?useSSL=false";
//    //  Database credentials 
//    static final String USER = "root"; 
//    static final String PASS = "9406"; 

	public int registerUser(User user) throws SQLException
	{
		String userName=user.getUserName();
		String password=user.getPassword();
		String email=user.getEmail();
		String contactNumber=user.getContactNumber();
		int rowCount=0;
//		Connection conn=null;
		//try{ 
	         // Register JDBC driver 
	         //Class.forName("com.mysql.jdbc.Driver"); 
	 
	         // Open a connection 
	         //conn = DriverManager.getConnection(DB_URL, USER, PASS); 
	         String sql="Insert into users(uname,upwd,uemail,umobile) values(?,?,?,?)";
	         PreparedStatement pst=conn.prepareStatement(sql);
	         
	         pst.setString(1, userName);
	         pst.setString(2, password);
	         pst.setString(3, email);
	         pst.setString(4, contactNumber);
	         
	         rowCount=pst.executeUpdate();
	         
	         
	         
//	    }
//		catch(Exception e)
//		{
//			e.printStackTrace();
//		}
//		finally
//		{
//			try {
//				conn.close();
//			} catch (SQLException e) {
//				// TODO Auto-generated catch block
//				e.printStackTrace();
//			}
//		}
		return rowCount;
			
			
		
	}
		
	
}
