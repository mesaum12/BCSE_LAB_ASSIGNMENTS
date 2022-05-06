<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
 
<%@ page import = "java.io.*" %>
<%@ page import = "java.util.ArrayList" %>
<%@ page import="com.saurabh.model.Flight" %>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>FlightDetails</title>
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css"
        crossorigin="anonymous">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.bundle.min.js">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.0.3/css/font-awesome.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.2.1/jquery.min.js">
</head>

<body>
<%
    System.out.println("Hello I am  here ! inside the display file !");
	ArrayList<Flight> flightList;
	flightList=(ArrayList<Flight>)request.getAttribute("FlightList");
	
%>


    <div class="container py-5">
        <div class="row text-center text-white mb-5">
            <div class="col-lg-7 mx-auto">
                <h1 class="display-4">Flight List</h1>
                
            </div>
        </div>
        <div class="row">
            <div class="col-lg-8 mx-auto">
                <!-- List group-->
                <ul class="list-group shadow">
                   
                    <!-- list group item-->
                     <% int count=0;
                       if(flightList!=null)
                    	{
                    	  for(Flight f:flightList)
                    	   {
                    		  count=(count%6)+1;
                      %>
		                     <li class="list-group-item">
		                        <!-- Custom content-->
		                        <div class="media align-items-lg-center flex-column flex-lg-row p-3">
		                            <div class="media-body order-2 order-lg-1">
		                                <h5 class="mt-0 font-weight-bold mb-2">Flight Id:<%=f.getFlightId() %></h5>
		                                <p class="font-italic text-muted mb-0 small">Source:<%=f.getSourceCity()%> | Destination City:<%=f.getDestinationCity() %>
		                                
		                           | Fare:<%=f.getCost() %>|Company:<%=f.getCompanyName() %>|Departure Time:<%=f.getDepartureTime() %>|
		                           Arrival Time:<%=f.getArrivalTime() %></p>
		                            
		                            
		                            </div><img src="<%="./img/img"+count+".webp" %>" alt="Generic placeholder image" width="200"
		                                class="ml-lg-5 order-1 order-lg-2">
		                        </div> <!-- End -->
		                    </li> <!-- End -->
                       <%
                    	    }//for ends here
                    	}//if ends here
                    	else 
                    	{
                       %>
                       <li class="list-group-item">
		                        <!-- Custom content-->
		                        <div class="media align-items-lg-center flex-column flex-lg-row p-3">
		                            <div class="media-body order-2 order-lg-1">
		                                <h4 class="mt-0 font-weight-bold mb-2">No Flights Found </h4>
		                           </div> <!-- End -->
		                           <img src="<%="./img/imgSorry.webp" %>" alt="Generic placeholder image" width="200"
		                                class="ml-lg-5 order-1 order-lg-2">
		                        </div>      
		                </li> <!-- End -->
		               <%} %>
                    
                   
                </ul> <!-- End -->
            </div>
        </div>
    </div>
</body>

</html>