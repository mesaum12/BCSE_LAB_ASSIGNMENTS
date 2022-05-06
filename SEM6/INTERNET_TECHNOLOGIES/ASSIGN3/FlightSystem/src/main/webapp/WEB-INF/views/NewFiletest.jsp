<!-- Final design for addition of flights . This page should open when admin logins successfully -->
<!-- On submission of this page , it should show a prompt and redirect it to the same page  -->

<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
    <%
    
    	  if(session.getAttribute("admin_name")==null)
    	  {
    		  response.sendRedirect("adminLogin.jsp");
    	  }
    		  
    %>
      
<!DOCTYPE html>
<html>

<head>
    <title>Add Flights</title>

    
    <link rel="stylesheet" type="text/css" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css">
    <link rel="stylesheet" type="text/css"
        href="https://cdnjs.cloudflare.com/ajax/libs/bootstrap-datetimepicker/4.17.37/css/bootstrap-datetimepicker.min.css">
    <style type="text/css">
        .container {
            margin-top: 40px;
            width: 50%;
        }

        .btn-primary {
            width: 100%;
        }
    </style>

    <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
    <script type="text/javascript" src="https://cdn.jsdelivr.net/momentjs/2.14.1/moment.min.js"></script>
    <script type="text/javascript" src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js"></script>
    <script type="text/javascript"
        src="https://cdnjs.cloudflare.com/ajax/libs/bootstrap-datetimepicker/4.17.37/js/bootstrap-datetimepicker.min.js"></script>

    <script type='text/javascript'>
        $(document).ready(function () {
            $('#datetimepicker1').datetimepicker();
        });
        $(document).ready(function () {
            $('#datetimepicker2').datetimepicker();
        });
        $(document).ready(function () {
            $('#datetimepicker3').datetimepicker();
        });
        $(document).ready(function () {
            $('#datetimepicker4').datetimepicker();
        });
    </script>

</head>

<body style="background: linear-gradient(to right, #33c5f1, #480048);">

<a href="<%=request.getContextPath()%>/AdminLogout?"><button  class="btn btn-danger">LogOut </button></a>


   <!--  <form action="<%=request.getContextPath()%>/register2" method="post">--> 
   <form action="<%=request.getContextPath()%>/InsertFlightIntoDatabase" method="post">
        <div class="container">
            <div class="panel panel-primary">
                <div class="panel-heading">Add Flight Details</div>
                <div class="panel-body">
                    <div class="row">
                        <div class="col-md-12">
                            <div class="form-group">
                                <label class="control-label">Flight Id </label>
                                <input type="text" class="form-control" name="flightId" id="fname">
                            </div>
                        </div>
                        <div class="col-md-12">
                            <div class="form-group">
                                <label class="control-label">Company Name</label>
                                <input type="text" class="form-control" name="companyName" id="lname">
                            </div>
                        </div>

                        <div class="col-md-12">
                            <div class="form-group">
                                <label class="control-label">Source </label>
                                <input type="text" class="form-control" name="sourceCity" id="lname">
                            </div>
                        </div>
                        <div class="col-md-12">
                            <div class="form-group">
                                <label class="control-label">Destination</label>
                                <input type="text" class="form-control" name="destinationCity" id="lname">
                            </div>
                        </div>
                        <div class="col-md-12">
                            <div class="form-group">
                                <label class="control-label">Fare</label>
                                <input type="text" class="form-control" name="fare" id="lname">
                            </div>
                        </div>
                    </div>
                    <div class="row">

                        <div class='col-md-12'>
                            <div class="form-group">
                                <label class="control-label">Departure Time</label>
                                <div class='input-group date' id='datetimepicker1'>
                                    <input type='text' class="form-control" name="departureTime" />
                                    <span class="input-group-addon">
                                        <span class="glyphicon glyphicon-calendar"></span>
                                    </span>
                                </div>
                            </div>
                            <div class="form-group">
                                <label class="control-label">Arrival Time</label>
                                <div class='input-group date' id='datetimepicker2'>
                                    <input type='text' class="form-control" name="arrivalTime" />
                                    <span class="input-group-addon">
                                        <span class="glyphicon glyphicon-calendar"></span>
                                    </span>
                                </div>
                            </div>
                            <div class="form-group">
                                <label class="control-label">Offer Start</label>
                                <div class='input-group date' id='datetimepicker3'>
                                    <input type='text' class="form-control" name="offerStart" />
                                    <span class="input-group-addon">
                                        <span class="glyphicon glyphicon-calendar"></span>
                                    </span>
                                </div>
                            </div>
                            <div class="form-group">
                                <label class="control-label">Offer Ends</label>
                                <div class='input-group date' id='datetimepicker4'>
                                    <input type='text' class="form-control" name="offerEnd" />
                                    <span class="input-group-addon">
                                        <span class="glyphicon glyphicon-calendar"></span>
                                    </span>
                                </div>
                            </div>
                        </div>
                        <div class="col-md-12">
                            <div class="form-group">
                                <label class="control-label">Discount</label>
                                <input type="text" class="form-control" name="discount" id="lname">
                            </div>
                        </div>
                    </div>
                    <input type="submit" class="btn btn-primary" value="Submit">
                    
                </div>
            </div>
        </div>
    </form>


</body>
</html>