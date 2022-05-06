
<%@page import="java.util.*"%>
<%@page import="java.text.SimpleDateFormat"%>
<%@page import="com.saurabh.DatabaseConnection.*" %>
<%@page import="com.saurabh.dao.*" %>
<%@page import="com.saurabh.model.*" %>
<%@page import="java.sql.*" %>
<%@page import="java.util.Calendar" %>
<%
  if(session.getAttribute("name")==null)
  {
	  response.sendRedirect("test.jsp");
  }
	  
%>


<%

MyDatabase mydata = (MyDatabase) getServletContext().getAttribute("Database");  
Connection con = mydata.getCon();  
if (con != null) {  
    System.out.println("Database is connected");  
} else {  
    System.out.println("Database is not connected");  
}  

SpecialDealsDao d=new SpecialDealsDao(con);


ResultSet resultSet = d.getOfferList();
%>



<!DOCTYPE html>
<html>

<head>
  <!--Import Google Icon Font-->
  <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
  <!--Import materialize.css-->
  <link type="text/css" rel="stylesheet" href="css2/materialize.min.css" media="screen,projection" />
  <link type="text/css" rel="stylesheet" href="css2/main.css" />
  <script defer src="https://use.fontawesome.com/releases/v5.0.6/js/all.js"></script>

  <!--Let browser know website is optimized for mobile-->
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Travel Thru Air</title>
</head>

<body id="home" class="scrollspy">
  <div class="navbar-fixed">
    <nav class="purple darken-4">
      <div class="container">
        <div class="nav-wrapper">
          <a href="#home" class="brand-logo">Travel Thru Air</a>
          <a href="#" data-activates="mobile-nav" class="button-collapse">
            <i class="material-icons">menu</i>
          </a>
          <ul class="right hide-on-med-and-down">
            <li><a href="#home">Home</a></li>
            <li><a href="#search">Search</a></li>
            <li><a href="#popular">Popular Places</a></li>
            <li><a href="#gallery">Gallery</a></li>
            <li><a href="#contact">Contact</a></li>
            <li><a href="<%=request.getContextPath()%>/UserLogout?">LogOut</a></li>
            
          </ul>
        </div>
      </div>
    </nav>
  </div>
  <ul class="side-nav" id="mobile-nav">
    <li><a href="#home">Home</a></li>
    <li><a href="#search">Search</a></li>
    <li><a href="#popular">Popular Places</a></li>
    <li><a href="#gallery">Gallery</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="<%=request.getContextPath()%>/UserLogout?">LogOut</a></li>
  </ul>

  <!-- Slider -->
  <section class="slider">
    <ul class="slides">
      <li><img src="img/img1.webp" alt="">
        <div class="caption center-align">
          <h2>Take Your Dream Vacation</h2>
          <h5 class="dark grey-text text-darken-4 hide-on-small-only">Travel the whole world in the most adventurous
            way!!</h5>
          <a href="#" class="btn btn-large purple darken-4 ">Learn More</a>
        </div>
      </li>

      <li><img src="img/img2.webp" alt="">
        <div class="caption left-align">
          <h2>Let's Fly through the heaven</h2>
          <h5 class="dark grey-text text-darken-4 hide-on-small-only">Experience the beauty of nature by hopping the
            world..</h5>
          <a href="#" class="btn btn-large purple darken-4">Learn More</a>
        </div>
      </li>

      <li><img src="img/img3.webp" alt="">
        <div class="caption right-align">
          <h2>Journey beyond the horizon</h2>
          <h5 class="dark grey-text text-darken-4 hide-on-small-only">Let's spend the most amazing part of our life ,
            let's travel..</h5>
          <a href="#" class="btn btn-large purple darken-4">Learn More</a>
        </div>
      </li>
    </ul>
  </section>

  <!-- Search -->
  <!--  <form action="<%=request.getContextPath()%>/GetFlightsFinal" method="post">-->
  <form action="<%=request.getContextPath()%>/RetrieveFlightFromDatabase" method="post">
    <section id="search" class="section section-search purple darken-4 white-text center scrollspy">
      <div class="container">
        <div class="row">
          <div class="col s12">
            <h3>Source </h3>
            <div class="input-field">
              <input class="white grey-text autocomplete" placeholder="NewYork, London, etc..." type="text"
                id="autocomplete-input" name="sourceName" required>
            </div>
          </div>
        </div>
      </div>
    </section>
    <section id="search" class="section section-search purple darken-4 white-text center scrollspy">
      <div class="container">
        <div class="row">
          <div class="col s12">
            <h3>Destination</h3>
            <div class="input-field">
              <input class="white grey-text autocomplete" placeholder="NewYork, London, etc..." type="text"
                id="autocomplete-input" name="destinationCity" required>
            </div>
          </div>
        </div>
      </div>
    </section>
    <section id="search" class="section section-search purple darken-4 white-text center scrollspy">
      <div class="container">
        <div class="row">
          <div class="col s12">
            <div class="input-field">
              <input style="color: black; border-radius: 30px; font-weight: bolder;" type="submit"
                value="Search Flights">
            </div>
          </div>
        </div>
      </div>
    </section>


  </form>


  <!-- Icon Boxes -->
  <section class="section section-icons grey lighten-4 center">
    <div class="container">
      <div class="row">
        <div class="col s12 m4">
          <div class="card-panel">
            <i class="material-icons large purple-text">room</i>
            <h4>Location</h4>
            <p>Best location in the world!</p>
          </div>
        </div>


        <div class="col s12 m4">
          <div class="card-panel">
            <i class="material-icons large purple-text">store</i>
            <h4>Fare</h4>
            <p>The best fare amongst all </p>
          </div>
        </div>

        <div class="col s12 m4">
          <div class="card-panel">
            <i class="material-icons large purple-text">airplanemode_active</i>
            <h4>Destination</h4>
            <p>Experience Life !</p>
          </div>
        </div>
      </div>
    </div>
  </section>

  <!-- popular places -->
  <section id="popular" class="section section-popular scrollspy">
    <div class="container">
      <div class="row">
        <h4 class="center">
          <span class="purple-text">Special Deals</span>
        </h4>
        
        <%
		
		try
        {
			
		    while(resultSet.next())
		    {
			%>
	        <div class="col s12 m4">
	          <div class="card">
	            
	            <div class="card-image">
	              <img src="img/deals.jpg" alt="">
	              <span class="card-title"><%=resultSet.getString("sourceCity") %> To <%=resultSet.getString("destinationCity") %></span>
	            </div>
	              
	             
	            <div class="card-content">
	               <p style="color:red; font-weight:bold; font-size=15px;">Grab the Best Offer </p>
	               <p style="color:blue; font-weight:bold;">Discount Offered:<%=resultSet.getDouble("discount") %></p>
	              
	               <p>Deal Starts On:<%=resultSet.getDate("offerStartDate") %></p>
	               <p>Deal Ends On:<%=resultSet.getDate("offerEndDate")%></p>
	               <p>Start Time (IST):<%= resultSet.getTime("offerStartTime") %></p>
	               <p style="color:blue; font-weight:bolder;">End Time(IST) :<%=resultSet.getTime("offerEndTime") %></p>
	            </div>
	            
	          </div>
	        </div>
	        <% 
				  }
				}
		        catch(Exception e)
		        {
		        	e.printStackTrace();
		        }
			
		      %>
			
			
      <div class="row">
        <div class="col s12 center">
          <a href="#contact" class="btn btn-large purple darken-4">
            <i class="material-icons left">send</i> Contact For Booking
          </a>
        </div>
      </div>
    </div>
    </div>
  </section>
		
		
		
		
  <!-- Follow -->
  <section class="section section-follow purple darken-4 white-text center">
    <div class="container">
      <div class="row">
        <div class="col s12">
          <h4>Follow Us</h4>
          <p>Get special offers on social medias</p>
          <a href="htttps://facebook.com" target="_blank" class="white-text">
            <i class="fab fa-facebook fa-4x"></i>
          </a>
          <a href="htttps://twitter.com" target="_blank" class="white-text">
            <i class="fab fa-twitter fa-4x"></i>
          </a>
          <a href="htttps://linkedin.com" target="_blank" class="white-text">
            <i class="fab fa-linkedin fa-4x"></i>
          </a>
          <a href="htttps://youtube.com" target="_blank" class="white-text">
            <i class="fab fa-youtube fa-4x"></i>
          </a>
          <a href="htttps://instagram.com" target="_blank" class="white-text">
            <i class="fab fa-instagram fa-4x"></i>
          </a>
        </div>
      </div>
    </div>
  </section>
		
	


  <!-- Gallery -->
  <section id="gallery" class="section section-gallery scrollspy">
    <div class="container">
      <h4 class="center">
        <span class="purple-text">Gallery</span>
      </h4>
      <div class="row">
        <div class="col s12 m3">
          <img class="materialboxed responsive-img" src="https://source.unsplash.com/1600x900/?beach" alt="">
        </div>

        <div class="col s12 m3">
          <img class="materialboxed responsive-img" src="https://source.unsplash.com/1600x900/?travel" alt="">
        </div>

        <div class="col s12 m3">
          <img class="materialboxed responsive-img" src="https://source.unsplash.com/1600x900/?nature" alt="">
        </div>

        <div class="col s12 m3">
          <img class="materialboxed responsive-img" src="https://source.unsplash.com/1600x900/?travel" alt="">
        </div>


      </div>

      <div class="row">
        <div class="col s12 m3">
          <img class="materialboxed responsive-img" src="https://source.unsplash.com/1600x900/?water" alt="">
        </div>

        <div class="col s12 m3">
          <img class="materialboxed responsive-img" src="https://source.unsplash.com/1600x900/?bridge" alt="">
        </div>

        <div class="col s12 m3">
          <img class="materialboxed responsive-img" src="https://source.unsplash.com/1600x900/?building" alt="">
        </div>

        <div class="col s12 m3">
          <img class="materialboxed responsive-img" src="https://source.unsplash.com/1600x900/?forest" alt="">
        </div>
      </div>

      <div class="row">
        <div class="col s12 m3">
          <img class="materialboxed responsive-img" src="https://source.unsplash.com/1600x900/?vehicle" alt="">
        </div>

        <div class="col s12 m3">
          <img class="materialboxed responsive-img" src="https://source.unsplash.com/1600x900/?travelling" alt="">
        </div>

        <div class="col s12 m3">
          <img class="materialboxed responsive-img" src="https://source.unsplash.com/1600x900/?safari" alt="">
        </div>

        <div class="col s12 m3">
          <img class="materialboxed responsive-img" src="https://source.unsplash.com/1600x900/?surfing" alt="">
        </div>
      </div>

    </div>
  </section>

  <!-- Contact -->
  <section id="contact" class="section-contact scrollspy">
    <div class="container">
      <div class="row">
        <div class="col s12 m6">
          <div class="card-panel purple white-text center">
            <i class="material-icons medium">email</i>
            <h5>Contact Us For Booking</h5>
            <p>We are always at your service!!</p>



          </div>
          <ul class="collection width-header">
            <li class="collection-header">
              <h4>Location</h4>
            </li>
            <li class="collection-item"> Travel-Through-Air</li>
            <li class="collection-item"> Jadavpur University</li>
            <li class="collection-item"> Kolkata ,700032</li>
          </ul>

        </div>

        <div class="col s12 m6">
          <div class="card-panel purple white-text">
            <h5>Please fill the form</h5>
            <div class="input-field">
              <input type="text" placeholder="Name" id="name">
              <label for="name">Name</label>
            </div>
            <div class="input-field">
              <input type="email" placeholder="Email" id="email">
              <label for="email">Email</label>
            </div>
            <div class="input-field">
              <input type="text" placeholder="Phone" id="phone">
              <label for="phone">Phone</label>
            </div>
            <div class="input-field">
              <textarea class="materialize-textarea" placeholder="Enter Message" id="message"></textarea>
              <label for="message">Message</label>
            </div>
            <input type="submit" value="Submit" class="btn  purple darken-4">
          </div>
        </div>

      </div>
    </div>
  </section>


  <!--Import jQuery before materialize.js-->
  <script type="text/javascript" src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
  <script type="text/javascript" src="js2/materialize.min.js"></script>
  <script>
    $(document).ready(function () {
      // init side-nav
      $('.button-collapse').sideNav();

      // init slider
      $('.slider').slider({
        indicators: false,
        height: 500,
        transition: 500,
        interval: 6000
      });

      //auto-complete
      $('.autocomplete').autocomplete({
        data: {
          "Europe": null,
          "America": null,
          "London": null,
          "Mexico": null,
          "Jamica": null,
          "China": null,
          "Pakistan": null
        }
      });

      // Init Scrollspy
      $('.scrollspy').scrollSpy();

    });
  </script>
</body>

</html>