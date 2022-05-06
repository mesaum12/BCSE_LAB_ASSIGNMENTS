<!-- Admin page initially , adding flights into database , no need in final project -->

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
<h1>FlightAdd</h1>
<form action="<%=request.getContextPath()%>/register" method="post">
<table>
<tr>
<td>Company Name:</td>
<td><input type="text" name="companyName"></td>
</tr>
<tr>
<td>Source City:</td>
<td><input type="text" name="sourceCity" /></td>
</tr>
<tr>
<td>Destination City:</td>
<td><input type="text" name="destinationCity" /></td>
</tr>
<tr>
<td>Fare:</td>
<td><input type="text" name="fare" /></td>
</tr>
</table>
<input type="submit" value="Submit" />
</form>
</div>
</body>
</html>
