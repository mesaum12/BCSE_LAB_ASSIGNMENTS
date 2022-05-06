package com.saurabh.TestingPhaseDao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
//import java.sql.ResultSet;
import java.sql.SQLException;

import com.saurabh.model.*;

public class FlightDao {

    public int registerFlight(Flight flight) throws ClassNotFoundException {
    

    	

    	int result = 0;
    	
    	Class.forName("com.mysql.jdbc.Driver");
    	int randomNum=(int)(Math.random()*10000000);
    	System.out.println(randomNum);
    	try (Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/FlightSystem", "root", "9406")) {

    	    try (PreparedStatement stmt = connection.prepareStatement("INSERT INTO FlightDetails (flightId,companyName,sourceCity) VALUES (?, ? ,?)")) {
    	        stmt.setInt(1,randomNum);
    	    	stmt.setString(2, flight.getCompanyName());   
    	        stmt.setString(3, flight.getSourceCity());           
    	        stmt.executeUpdate();
    	    }
    	    // stmt is auto closed here, even if SQLException is thrown

    	    try (PreparedStatement stmt = connection.prepareStatement("INSERT INTO DestinationDetails (flightId,destinationName,price) VALUES (?, ?, ?)")){
    	        stmt.setInt(1,randomNum);  
    	        stmt.setString(2, flight.getDestinationCity());
    	        stmt.setDouble(3, flight.getCost());
    	        stmt.executeUpdate();
    	    }
    	    // stmt is auto closed here, even if SQLException is thrown
    	}
    	catch (SQLException e) 
    	{
    		// process sql exception
    		System.out.println("Hello :-;--;");
    		printSQLException(e);
    	}
    	


		    return result;
    }

    private void printSQLException(SQLException ex) {
        for (Throwable e: ex) {
            if (e instanceof SQLException) {
                e.printStackTrace(System.err);
                System.err.println("SQLState: " + ((SQLException) e).getSQLState());
                System.err.println("Error Code: " + ((SQLException) e).getErrorCode());
                System.err.println("Message: " + e.getMessage());
                Throwable t = ex.getCause();
                while (t != null) {
                    System.out.println("Cause: " + t);
                    t = t.getCause();
                }
            }
        }
    }
}