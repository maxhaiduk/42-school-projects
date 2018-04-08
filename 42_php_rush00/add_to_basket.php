<?php
	require_once('appvars.php');
	
	session_start();
	print_r($_GET);
	$_SESSION['booking'][] = $_GET['prod_id'];
	header('Location: ' . HOME_PAGE . '?category=' . $_GET['category']);
?>