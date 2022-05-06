<!-- Redundant page which was used earlier for searching of the flights, no need in final project  -->

<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>FlightAddIntoDatabase</title>
</head>
<body>
<div>
<h1>FlightSearch</h1>
<form action="<%=request.getContextPath()%>/GetFlight" method="post">
<table>
<tr>
<td>Source City:</td>
<td><input type="text" name="sourceName"></td>
</tr>
<tr>
<td>Destination:</td>
<td><input type="text" name="destinationCity" /></td>
</tr>
</table>
<input type="submit" value="Search" />
</form>
</div>
</body>
</html>

