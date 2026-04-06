<?php
	require_once('appvars.php');
	if (isset($_SESSION['login']))
		$_SESSION = array();
	if (isset($_COOKIE[session_name()]))
		setcookie(session_name(), time() - 3600);
	session_destroy();
	header('Location: ' . HOME_PAGE);
?>