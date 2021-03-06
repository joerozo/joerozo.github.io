<!DOCTYPE html>
<html>
<head>
<link href='http://fonts.googleapis.com/css?family=Lato:300,700' rel='stylesheet' type='text/css'>
<!-- stylesheets -->
<link rel="stylesheet" href="style.css" type="text/css" />

<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
<script src="jquery-1.12.4.min.js"></script>
<script src="https://ajax.googleapis.com/ajax/libs/angularjs/1.4.8/angular.min.js"></script>
<script>
$(document).ready(function(){
	$(".matrixProject").hide();
	$(".sqlProject").hide();
	$(".workMenuButton1PopUp").hide();
	$(".workAndProjectsMenu").hide();
    $(".resumeBox").hide();
    $(".topBox").hide();
    $(".centerBox").hide();
    $(".contactBox").hide();
    $(".sqlProject").click(function(){
    	$(".sqlProject").hide();
    	$(".workAndProjectsMenu").show();
    });
    $(".bottomButton").click(function(){
    	$(".workAndProjectsMenu").hide();
    	$(".sqlProject").hide();
    	$(".centerBox").show();
    });
    $(".workMenuButton1").click(function(){
    	$(".sqlProject").show();
    	$(".workAndProjectsMenu").hide();

    });
    	$(".workMenuButton1").mouseenter(function(){
    		$(".workMenuButton1PopUp").show();
    	});
    	$(".workMenuButton1").mouseleave(function(){
    		$(".workMenuButton1PopUp").hide();
    	});
        $(".button3").click(function(){
        $( ".contactBox" ).slideToggle( "slow", function() {});
        $(".centerBox").hide();
    });
        $(".buttonBox3").click(function(){
        	$( ".contactBox" ).hide();
        	$(".centerBox").show();
        });
    $(".button1").click(function(){
        $( ".resumeBox" ).slideToggle( "slow", function() {});
        $(".centerBox").hide();
    });
        $(".buttonBox").click(function(){
        $(".resumeBox").hide();
        $(".centerBox").show();
    }); 

    $(".container").click(function(){
        $(".container").hide();
        $(".redBorder").hide();
        $( ".topBox" ).slideDown( "slow", function() {});
        $( ".centerBox" ).slideDown( "slow", function() {});
    });
    $(".button4").click(function(){
        $( ".workAndProjectsMenu" ).slideToggle( "slow", function() {});
        $(".centerBox").hide();
    });

    $(".workMenuButton2").mouseenter(function(){
    		$(".workMenuButton2PopUp").show();
    	});
    	$(".workMenuButton2").mouseleave(function(){
    		$(".workMenuButton2PopUp").hide();
    });
    $(".workMenuButton2").click(function(){
    	$(".matrixProject").show();
    	$(".workAndProjectsMenu").hide();
    });
    $(".matrixProject").click(function(){
    	$(".matrixProject").hide();
    	$(".workAndProjectsMenu").show();
    });
});
</script>

</head>
<body ng-app="myApp">



<div class="resumeBox">
<button type="button" class="buttonBox">Return to menu</button>
<div class="resume">
<object width="650" height="650" data="doc/resume.pdf" ></object>
</div>
</div>

<div class="centerBox"> 
	<div class="button1">view my resume</div>
	<div class="button2"><a href="https://github.com/joerozo">go to my github</a></div>
	<div class="button3">contact</div>
	<div class="button4">code, work, and projects</div> 
	<div class="button3">technical writings</div>
	<w3-test-directive></w3-test-directive>
	The current date is
		<% import datetime
			print datetime.date.today().strftime("%d:%m:%y")
		%>
	<object width="250" height="300" data="img/image1.png" class="image1"></object>
</div>

<div class="workAndProjectsMenu"> 
	<div class="workMenuButton1">SQL Code</div>
	<div class="workMenuButton1PopUp">
		Program that demonstrates how to utilize java to connect to a SQL database and execute Queries 
	</div>

	<div class="workMenuButton2"> Java linkedList Matrix Calculator</div>
	<div class="workMenuButton2PopUp">
		A java program which allows for uploading a matrix (matrix as linkedList of linkedListsts) and peforming
		matrix operations
	</div>
	<button type="button" class="bottomButton">go back to menu</div>
</div>
<div class="matrixProject">
	Matrix Project coming
</div>


<div class="sqlProject">
	<p>
	<pre>
import java.sql.*;
import java.util.*;

public class StoreApplication {
	 /* Returns a list of phone numbers of customers, given a first name and
	 * last name.
	 */
	public List<String> getCustomerPhoneFromFirstLastName(Connection connection,
		String firstName, String lastName) {
		List<String> result = new ArrayList<String>();
		String sqlString = "Select x.phone from dv_address x, mg_customers y where y.last_name = '" + lastName + "' and y.first_name = '" + firstName + "' and y.address_id = x.address_id";
		try(Statement stmt = connection.createStatement())
		{
			ResultSet RS = stmt.executeQuery(sqlString);
			while(RS.next()){
				result.add(RS.getString("phone"));
			}
		}
		catch (SQLException e){
			System.err.println(e);
                	//System.exit(-1);
		}
		{
		}
		return result;
	}

	/**
	 * Returns list of film titles whose length is is equal to or greater
	 * than the minimum length, and less than or equal to the maximum
	 * length.
	 */
	public List<String> getFilmTitlesBasedOnLengthRange(Connection connection,
		int minLength, int maxLength) {
		List<String> result = new ArrayList<String>();
		String sqlString = "Select title from dv_film where length <= " + maxLength + " and length >= " + minLength ;
		try(Statement stmt = connection.createStatement())
		{
			ResultSet RS = stmt.executeQuery(sqlString);
			while(RS.next()){
				result.add(RS.getString("title"));
			}
		}
		catch (SQLException e){  
			System.err.println(e);
				//System.exit(-1);

		}
		
		return result;
	}

	/**
	 * Returns the number of customers that live in a given district and
	 * have the given active status.
	 */
		public final int countCustomersInDistrict(Connection connection,
			String districtName, boolean active) {
			int result = -1;
			String sqlString = "select count(*) from dv_address x, mg_customers y where x.address_id = y.address_id and y.active =" + active + " and x.district = '" + districtName + "'";
			try(Statement stmt = connection.createStatement())
			{
				ResultSet RS = stmt.executeQuery(sqlString);
				while(RS.next()){
					result = RS.getInt("count");
				}
			}
			catch(SQLException e){
				System.err.print(e);
				//System.exit(-1);
			}

			return result;
		}

	/**
	 * Adds a film to the inventory, given its title, description,
	 * length, and rating.
	 *
	 * Your query will need to cast the rating parameter to the
	 * enumerated type mpaa_rating. Whereas an uncast parameter is
	 * simply a question mark, casting would look like ?::mpaa_rating 
	 */ 

	public void insertFilmIntoInventory(Connection connection, String
		title, String description, int length, String rating)
	{
		String sqlString = "insert into dv_film(title, description, length, rating) VALUES('" + title +"', '"+ description +"',"+ length +",'"+ rating +"')";
		try(PreparedStatement stmt = connection.prepareStatement(sqlString)){
			stmt.executeUpdate();
			System.out.println("successfully inserted movie!");
		}
		catch(SQLException e){
			System.out.print(e);
		}
		

	}

	/**
	 * Constructor
	 */
	public StoreApplication()
	{}

};
	</pre>
	</p>
</div>

<div class="redBorder">
	<div class="container">
		<p> Welcome</p>
	</div>
</div>

<div class="contactBox">
	<button type="button" class="buttonBox3">Return to menu</button>
	<div class="redFill"><p> <i>by email:</i> jrozo@ucsc.edu</p></div>
	<br>
	<div class="redFill"><p> <i>by phone:</i> (707)299-8538</p></div>
</div>

<script>
var app = angular.module("myApp", []);
app.directive("w3TestDirective", function() {
    return {
        template : "<h1>Made by a directive!</h1>"
    };
});
</script>


</body>



</html>