<?php
	require_once('connectvars.php');
	require_once('appvars.php');
	session_start();
	$dbc = mysqli_connect(DB_HOST, DB_USER, DB_PASS, DB_NAME) 
		or die("DATA BASE CONNECTION ERROR");	
	$query = "SELECT * FROM `products` WHERE id IN(".implode(",", $_SESSION['booking']).")";
	$data = mysqli_query($dbc, $query);
	$total_price = 0;
	while ($row = mysqli_fetch_array($data))
		$total_price += $row['price'];
	$_SESSION['total_price'] = $total_price;
	mysqli_close($dbc);
?>