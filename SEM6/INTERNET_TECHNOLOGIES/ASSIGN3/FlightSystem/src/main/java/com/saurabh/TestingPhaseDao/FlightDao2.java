package com.saurabh.TestingPhaseDao;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import com.saurabh.model.Flight;

public class FlightDao2
{ 
      // JDBC driver name and database URL 
      static final String JDBC_DRIVER="com.mysql.jdbc.Driver";   
      static final String DB_URL="jdbc:mysql://localhost:3306/FlightSystem";
      //  Database credentials 
      static final String USER = "root"; 
      static final String PASS = "9406"; 
 
  public ArrayList<Flight> showFlightDestination(Flight f)
  { 
	  ArrayList<Flight> flightList=new ArrayList<>();
 
    try{ 
         // Register JDBC driver 
         Class.forName("com.mysql.jdbc.Driver"); 
 
         // Open a connection 
         Connection conn = DriverManager.getConnection(DB_URL, USER, PASS); 
         String sourceName=f.getSourceCity();
         System.out.println("The source city is : "+sourceName+"Just Checking");
         String destinationName=f.getDestinationCity();
         String sql2="SELECT FlightDetails.flightId,FlightDetails.companyName,DestinationDetails.destinationName,DestinationDetails.price from FlightDetails "+ 
        		 "INNER JOIN DestinationDetails ON FlightDetails.flightId=DestinationDetails.flightId where FlightDetails.sourceCity="+"'"+sourceName+"'";
         
         
         PreparedStatement stmt = conn.prepareStatement(sql2); 
         ResultSet rs = stmt.executeQuery(); 
         // Extract data from result set 
         
        
         while(rs.next()){ 
        	 //Retrieve by column name 
        	 String flightId  = Integer.toString(rs.getInt("flightId")); 
        	 String companyName = rs.getString("companyName"); 
        	 String dest = rs.getString("destinationName"); 
        	 float price = rs.getFloat("price"); 
        	 
        	 Flight flight=new Flight();
        	 flight.setFlightId(flightId);
        	 flight.setSourceCity(sourceName);
        	 flight.setCompanyName(companyName);
        	 flight.setDestinationCity(dest);
        	 flight.setCost((double)price);
        	 
        	 flightList.add(flight);
        	 System.out.println(flightId);
        	 System.out.println(companyName);
        	 System.out.println(dest);
        	 System.out.println(price);
        	 if(dest.equals(destinationName))break;
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
    return flightList;
  } 
} 
         
         
         
        
         
         
         
         


        	 
        	 
         
         
 
 
 
