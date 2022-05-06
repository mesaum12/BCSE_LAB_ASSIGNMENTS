package com.saurabh.TestingPhaseDao;

import java.sql.Connection;

import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Time;
import java.text.SimpleDateFormat;
import java.util.Date;

import com.saurabh.model.*;

public class FlightDao3 {

    public int registerFlight(Flight flight) throws ClassNotFoundException {
    
    	int result = 0;
    	Class.forName("com.mysql.jdbc.Driver");
    	try (Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/FlightSystem?", "root", "9406")) {
    		
    		if(flight.getOfferEntered())
    		{
    			try (PreparedStatement stmt = connection.prepareStatement("INSERT INTO FlightDetails2 VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?)")) {
        			
    				
    			   SimpleDateFormat format=new SimpleDateFormat("dd/MM/yyyy");
    			   SimpleDateFormat format2=new SimpleDateFormat("HH:mm:ss");
//    			   java.sql.Date d2;
    			   String arrivalTime=flight.getArrivalTime();
    			   System.out.println(arrivalTime);
//    			   String date,time;
    				
    			   
    			   System.out.println("First try with offer value entered ");
    			   
    			   

    			   stmt.setInt(1,Integer.parseInt(flight.getFlightId()));
    			   stmt.setString(2, flight.getCompanyName());   
    			   stmt.setString(3, flight.getSourceCity());
    			   stmt.setString(4, flight.getDestinationCity());
    			   System.out.println(new java.sql.Date(format.parse(flight.getArrivalDate()).getTime())); 
    			   
    			   
   				   
    			   //setting the time 
//    			   stmt.setString(5, flight.getArrivalTime());
    			   
//    			   t=new Time(format2.parse(flight.getArrivalTime()).getTime());
    			   
    			   stmt.setTime(5, new Time(format2.parse(flight.getArrivalTime()).getTime()));
//    			   stmt.setString(6, flight.getArrivalDate());
    			   stmt.setDate(6, new java.sql.Date(format.parse(flight.getArrivalDate()).getTime()));
    			   
//    			   stmt.setString(7, flight.getDepartureTime());
    			   stmt.setTime(7, new Time(format2.parse(flight.getDepartureTime()).getTime()));
//    			   stmt.setString(8, flight.getDepartureDate());
    			   stmt.setDate(8, new java.sql.Date(format.parse(flight.getDepartureDate()).getTime()));
//    			   stmt.setString(9, flight.getOfferStartDate());
    			   stmt.setDate(9, new java.sql.Date(format.parse(flight.getOfferStartDate()).getTime()));
//    			   stmt.setString(10, flight.getOfferStartTime());
    			   stmt.setTime(10, new Time(format2.parse(flight.getOfferStartTime()).getTime()));
//    			   stmt.setString(11, flight.getOfferEndDate());
    			   stmt.setDate(11, new java.sql.Date(format.parse(flight.getOfferEndDate()).getTime()));
//    			   stmt.setString(12, flight.getOfferEndTime());
    			   stmt.setTime(12, new Time(format2.parse(flight.getOfferEndTime()).getTime()));
    			   
    			   stmt.setDouble(13, flight.getDiscount());
    			   stmt.setDouble(14, flight.getCost());
   				
   				   
    			   stmt.executeUpdate();
    			   
    			}
    			
    			catch (SQLException e) 
    			{
    				// process sql exception
    				System.out.println("Error in FlighDao3");
    				printSQLException(e);
    			}
   				
   				
   				
    				
    				
    				
    				
    				
        	
    			
    		}//if ends here
    		else
    		{
                try (PreparedStatement stmt = connection.prepareStatement("INSERT INTO FlightDetails2(flightId,companyName,sourceCity,destinationCity,fare,arrivalTime,arrivalDate,departureTime,departureDate) VALUES (?,?,?,?,?,?,?,?,?)")) {
         			
                	
                	SimpleDateFormat format=new SimpleDateFormat("dd/MM/yyyy");
     			    SimpleDateFormat format2=new SimpleDateFormat("HH:mm:ss");
                	System.out.println("First try with offer value not entered ");
                	System.out.println(flight.getFlightId());
                	String arrivalTime=flight.getArrivalDate();
     			    System.out.println("Arrival Time ko print krke dekhe"+arrivalTime);
     				
                	
    				stmt.setInt(1,Integer.parseInt(flight.getFlightId()));
    				stmt.setString(2, flight.getCompanyName());   
    				stmt.setString(3, flight.getSourceCity());
    				stmt.setString(4, flight.getDestinationCity());
    				stmt.setDouble(5, flight.getCost());
//    				stmt.setString(5, flight.getArrivalTime());
//    				stmt.setString(6, flight.getArrivalDate());
//    				stmt.setString(7, flight.getDepartureTime());
//    				stmt.setString(8, flight.getDepartureDate());
                   
    				String date=flight.getArrivalDate();
    				String time=flight.getArrivalTime();
    				
    				System.out.println("Checking the time "+time);
//    				SimpleDateFormat format=new SimpleDateFormat("yyyy-MM-dd");
//    				java.util.Date javadate;
//    				javadate=format.parse(date);//for parsing the date 
//    				//convert the date into sql format 
//    				java.sql.Date d2=new java.sql.Date(javadate.getTime());
    				
    				
//    				SimpleDateFormat format2=new SimpleDateFormat("HH:mm:ss");
//    	            java.util.Date javadate3;
//    	            javadate3=format2.parse(time);
//                    Time t=new Time(javadate3.getTime());
    				
    				
   				
    			      
    				//set the date
    				stmt.setTime(6, new Time(format2.parse(flight.getArrivalTime()).getTime()));
    				stmt.setDate(7, new java.sql.Date(format.parse(flight.getArrivalDate()).getTime()));
    				stmt.setTime(8, new Time(format2.parse(flight.getDepartureTime()).getTime()));
    				stmt.setDate(9, new java.sql.Date(format.parse(flight.getDepartureDate()).getTime()));
    				
    				stmt.executeUpdate();
    				
                }
                catch (SQLException e) 
                {
                	// process sql exception
                	System.out.println("Error in FlighDao3 part 2");
                	printSQLException(e);
                }
    				
    		}
    		
    	}//outer try ends here
    	catch(Exception e)
    	{
    		System.out.println("Error in FlighDao3 outermost try");
    		e.printStackTrace();
    		
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


    				
    				
    				
    				
    				
    		       
    				
    				
    				
        	
    			

    	
    	    
    	   
    	
    	


