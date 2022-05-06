package com.saurabh.TestingPhaseController;
import java.io.IOException;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.saurabh.TestingPhaseDao.FlightDao;
import com.saurabh.model.Flight;

//adding flights into the database by taking input from admin
@WebServlet("/register")
public class FlightServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    
    public FlightServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
		RequestDispatcher requestDispatcher=request.getRequestDispatcher("/WEB-INF/views/NewFile.jsp");
		requestDispatcher.forward(request, response);
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		//get all the details from the submitted form 
		String companyName=request.getParameter("companyName");
		String sourceCity=request.getParameter("sourceCity");
		String destinationCity=request.getParameter("destinationCity");
		String fare=request.getParameter("fare");
		
		System.out.println("Fare:"+fare);
		
		//set a flight item to be put into the database
		FlightDao flightDao=new FlightDao();
		Flight f=new Flight();
		f.setCompanyName(companyName);
		f.setSourceCity(sourceCity);
	    f.setDestinationCity(destinationCity);
	    f.setCost(Double.parseDouble(fare));
	    
	    //save the value into the database 
		try {
			flightDao.registerFlight(f);
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		RequestDispatcher rd=request.getRequestDispatcher("/WEB-INF/views/display.jsp");
		rd.forward(request, response);
		
	}

}
