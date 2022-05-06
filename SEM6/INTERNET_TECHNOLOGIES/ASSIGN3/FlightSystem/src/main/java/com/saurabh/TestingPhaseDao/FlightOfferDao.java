package com.saurabh.TestingPhaseDao;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.*;

import com.saurabh.model.Offer;

public class FlightOfferDao
{ 
      // JDBC driver name and database URL 
      static final String JDBC_DRIVER="com.mysql.jdbc.Driver";   
      static final String DB_URL="jdbc:mysql://localhost:3306/FlightSystem";
      //  Database credentials 
      static final String USER = "root"; 
      static final String PASS = "9406"; 
 
  public ArrayList<Offer> getOfferList()
  { 
	  ArrayList<Offer> OfferList=new ArrayList<>();
 
    try{ 
         // Register JDBC driver 
         Class.forName("com.mysql.jdbc.Driver"); 
 
         // Open a connection 
         Connection conn = DriverManager.getConnection(DB_URL, USER, PASS); 
         
         
         String sql2="select * from offers2 where expiryDate>=?";
         PreparedStatement stmt = conn.prepareStatement(sql2);
        		 stmt.setString(0, new SimpleDateFormat("YYYY-MM-DD").format(new Date())); 
         ResultSet rs = stmt.executeQuery(); 
         // Extract data from result set 
         System.out.println("rwitick CHEWTIYA");
         System.out.println(stmt.toString());
        
         while(rs.next()){ 
        	 
        	 //Retrieve by column name 
        	 String sourceCity  = rs.getString("sourceCity");
        	 String destinationCity =rs.getString("destinationCity");
        	 float discountPercent = rs.getFloat("discountPercent"); 
        	 
        	 Offer offer=new Offer();
        	 offer.setSourceName(sourceCity);
        	 offer.setDestinationCity(destinationCity);
        	 offer.setDiscountPercent(discountPercent);
        	 
        	 OfferList.add(offer);
        	 
         } 
         
         
         // Clean-up environment 
         rs.close(); 
         stmt.close(); 
         conn.close(); 
    }
    catch(SQLException se){ 
    	//Handle errors for JDBC 
    	se.printStackTrace(); 
    }
    catch(Exception e){ 
    	//Handle errors for Class.forName 
    	e.printStackTrace(); 
    }
    return OfferList;
  } 
} 
         
         
         
        
         
         
         
         


        	 
        	 
         
         
 
 
 
