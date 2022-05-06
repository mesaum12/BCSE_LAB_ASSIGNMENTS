package com.saurabh.TestingPhaseController;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
//import com.saurabh.dao.FlightDao2;
import com.saurabh.TestingPhaseDao.FlightDao2;
import com.saurabh.model.Flight;


@WebServlet("/GetFlights")
public class GetFlights extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    
    public GetFlights() {
        super();
        // TODO Auto-generated constructor stub
    }

	
	 
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
		RequestDispatcher rd=request.getRequestDispatcher("/WEB-INF/views/NewFile1.jsp");
		rd.forward(request, response);//forward the request and response
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub

		//we need to call the dao to fetch the flights from the server now .
		
		String sourceName=request.getParameter("sourceName");
		String destinationCity=request.getParameter("destinationCity");
		System.out.println(sourceName);
		System.out.print(destinationCity);
		
		request.setAttribute("sourceName",sourceName);
		
		FlightDao2 flightDao2=new FlightDao2();
		Flight f=new Flight();
		
		f.setSourceCity(sourceName);//setting the sourceCity name for a flight 
	    f.setDestinationCity(destinationCity);//setting the destination for the flight
	    
	   
		//call the DAO to get the destination details for the flight and the price 
		ArrayList<Flight> flightList=flightDao2.showFlightDestination(f);
		
		request.setAttribute("FlightList", flightList);
//		RequestDispatcher rd=request.getRequestDispatcher("WEB-INF/views/showFlights.jsp");
		RequestDispatcher rd=request.getRequestDispatcher("showFlights.jsp");
		rd.forward(request, response);
	}
		
		

}
