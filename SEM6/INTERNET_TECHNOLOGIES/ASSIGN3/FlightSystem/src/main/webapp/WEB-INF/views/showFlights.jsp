<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@ page import = "java.io.*" %>
<%@ page import = "java.util.ArrayList" %>
<%@ page import="com.saurabh.model.Flight" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<%
    System.out.println("Hello I am  here ! inside the display file !");
	ArrayList<Flight> flightList;
	flightList=(ArrayList<Flight>)request.getAttribute("FlightList");
	if(flightList==null)
	{
%>
<h1>No such flight found!</h1>
<%
	}
	else
	{
	  for(Flight f:flightList)
	  {
%>
<h6>FlightId:<%=f.getFlightId() %></h6>
<h6>Source:  <%=f.getSourceCity()%></h6>
<h6>Destination City:<%=f.getDestinationCity() %></h6>
<h6>Price:<%=f.getCost() %></h6>
<%
     
	  }
	}
%>

</body>
</html>
