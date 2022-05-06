package com.saurabh.TestingPhaseDao;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Time;
import java.util.ArrayList;

import com.saurabh.model.Flight;

public class FlightDao2Final
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
         //Final source and destination
         String sourceName=f.getSourceCity();
         System.out.println("The source city is : "+sourceName+"Just Checking");
//         String destinationName=f.getDestinationCity();
         String sql2="SELECT * from FlightDetails2";
        		 
         
         
         PreparedStatement stmt = conn.prepareStatement(sql2); 
         ResultSet rs = stmt.executeQuery(); 
         // Extract data from result set 
         
        
        String flightId ,companyName ,sourceCity ,destinationCity ,arrivalTime  ,departureTime ;
        double fare; 
        Time t;
        
        
         while(rs.next()){ 
        	 //Retrieve by column name 
        	 System.out.print("-----Inside the result set----");
        	 flightId  = Integer.toString(rs.getInt("flightId")); 
        	 companyName = rs.getString("companyName"); 
        	 sourceCity=rs.getString("sourceCity");
        	 destinationCity = rs.getString("destinationCity"); 
        	 fare = rs.getDouble("fare"); 
        	 t=rs.getTime("arrivalTime");
        	 arrivalTime=t.toString();
        	 t=rs.getTime("departureTime");
        	 departureTime=t.toString();
        	 
        	 
        	 
        	 Flight flight=new Flight();
        	 flight.setFlightId(flightId);
        	 flight.setSourceCity(sourceCity);
        	 flight.setDestinationCity(destinationCity);
        	 flight.setCompanyName(companyName);
        	 flight.setArrivalTime(arrivalTime);
        	 flight.setDepartureTime(departureTime);
        	 flight.setCost(fare);
        	 
        	 flightList.add(flight);
//        	 System.out.println(flightId);
//        	 System.out.println(companyName);
//        	 System.out.println(destinationCity);
//        	 System.out.println(fare);
        	 
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
         
         
         
        
         
         
         
         


        	 
        	 
         
         
 
 
 
