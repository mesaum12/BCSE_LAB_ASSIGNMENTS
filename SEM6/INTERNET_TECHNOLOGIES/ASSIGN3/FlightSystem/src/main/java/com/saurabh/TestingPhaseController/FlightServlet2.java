//servlet which performs the addition of flights action into our database




package com.saurabh.TestingPhaseController;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

//import com.saurabh.dao.FlightDao;
import com.saurabh.dao.FlightDao3;
import com.saurabh.model.DateTimeSeparator;
import com.saurabh.model.Flight;
//adding flights final page design
@WebServlet("/register2")
public class FlightServlet2 extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    
    public FlightServlet2() {
        super();
        // TODO Auto-generated constructor stub
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		RequestDispatcher requestDispatcher=request.getRequestDispatcher("/WEB-INF/views/NewFiletest.jsp");
		requestDispatcher.forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		//fetch all the parameter which are submitted by the user in the form 
		String resultDate = null,resultTime=null;
		
		String flightId=request.getParameter("flightId");
		System.out.println("Hello"+flightId);
		
		String companyName=request.getParameter("companyName");
		System.out.println("Hello"+companyName);
		
		String sourceCity=request.getParameter("sourceCity");
		System.out.println("Hello"+sourceCity);
		
		String destinationCity=request.getParameter("destinationCity");
		System.out.println("Hello"+destinationCity);
		
		
		String departureTime=request.getParameter("departureTime");
		System.out.println("Hello"+departureTime);
		
		
		String arrivalTime=request.getParameter("arrivalTime");
		System.out.println("Hello"+arrivalTime);
		
		String offerStart =request.getParameter("offerStart");
		System.out.println("Hello"+offerStart);
		
		String offerEnd=request.getParameter("offerEnd");
		System.out.println("Hello"+offerEnd);
		
		String fare=request.getParameter("fare");
		System.out.println("Hello"+fare);
		
		String discount=request.getParameter("discount");
		System.out.println("Hello"+discount);
		
		
		
		DateTimeSeparator d=new DateTimeSeparator();
		FlightDao3 flightDao=new FlightDao3();
		Flight f=new Flight();
		
		//set the mandatory properties for flight
		String result[]=null;
		f.setFlightId(flightId);
		f.setCompanyName(companyName);
		f.setSourceCity(sourceCity);
		f.setDestinationCity(destinationCity);
		f.setCost(Double.parseDouble(fare));
		
		//change the result array
		result=d.DateTimeMySqlFormat(departureTime, resultDate, resultTime);
		f.setDepartureTime(result[1]);
		f.setDepartureDate(result[0]);
		
		System.out.println("saurabh saurabhResultDate:"+result[0]);
		//set the arrivalTime and date of the flight 
		result=d.DateTimeMySqlFormat(arrivalTime, resultDate, resultTime);
		System.out.println("saurabh saurabhResultDate:"+result[0]);
		
		f.setArrivalTime(result[1]);
		f.setArrivalDate(result[0]);
		f.setOfferEntered(false);
		
		
		
		//optional in terms of our application 
		
		if(offerStart!="" && offerEnd!="" && discount!="")
		{
			f.setOfferEntered(true);//set the offer entered true so that it is valid
			result=d.DateTimeMySqlFormat(offerStart, resultDate, resultTime);
			f.setOfferStartDate(result[0]);
			f.setOfferStartTime(result[1]);
			result=d.DateTimeMySqlFormat(offerEnd, resultDate, resultTime);
			f.setOfferEndTime(result[1]);
			f.setOfferEndDate(result[0]);
			f.setDiscount(Double.parseDouble(discount));
		}
		//save the value into the database 
		try {
			flightDao.registerFlight(f);
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		//printing on the server side in order to check the values 
		System.out.println(companyName);
		System.out.println(sourceCity);
		System.out.println(destinationCity);
		System.out.println(fare);
		System.out.println(discount);
		System.out.println("Departure Time:"+departureTime.substring(17));
		System.out.println("Arrival Time:"+arrivalTime);
		
//		RequestDispatcher rd=request.getRequestDispatcher("/WEB-INF/views/display.jsp");
		RequestDispatcher rd=request.getRequestDispatcher("/WEB-INF/views/NewFiletest.jsp");
		
		rd.forward(request, response);
		
	}
	
}
		
		
		
		
		
		
			
			
	    
	    
	    
		
		
		
		
