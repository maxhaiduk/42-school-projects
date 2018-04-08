<?php
	function log_in($login)
	{
		session_start();
		$_SESSION['login'] = $login;
		header('Location: ' . HOME_PAGE);
	}

	$msg = "";
	require_once('connectvars.php');
	require_once('appvars.php');

	if ($_POST['submit'] == 'OK' and 
		!empty($_POST['login']) and 
		!empty($_POST['password']))
	{
		$login = $_POST['login'];
		$password = hash('whirlpool', $_POST['password']);

		$dbc = mysqli_connect(DB_HOST, DB_USER, DB_PASS, DB_NAME) 
		 	or die("DATA BASE CONNECTION ERROR");
		$query = "SELECT * FROM users WHERE login='" . $login . "'";
		$sql = mysqli_query($dbc, $query);
		
		$rowcount = mysqli_num_rows($sql);
		
		/* CREATE ACCOUNT BLOCK */
		if ($_POST['create'] and $rowcount == 0)
		{
			$query = "	INSERT INTO 
						users (login, password) 
						VALUES ('" . $login . "', '" . $password . "')";

			mysqli_query($dbc, $query) or die ("ACCOUNT CREATION ERROR");
			log_in($login);
		}
		else if ($_POST['create'] and $rowcount == 1)
			$msg = "User with name <strong>$login </strong> is already exists";
		
		/* LOGIN BLOCK*/
		else if (!$_POST['create'] and $rowcount == 1)
		{
			$user = mysqli_fetch_array($sql);
			if ($user['password'] == $password)
				log_in($login);
			else
				$msg = "Wrong password";
		}
		else if (!$_POST['create'] and $rowcount == 0)
		{
			$msg = "Wrong login";
		}
		
	}
	else if ($_POST['submit'] == 'OK' and empty($_POST['login']))
		$msg = "Empty login field";
	else if ($_POST['submit'] == 'OK' and empty($_POST['password']))
		$msg = "Empty password field";

?>
<!DOCTYPE html>
<html><body>
	<form  method="POST" action="log_in.php">
		Username: <input type="text" name="login"/>
		<br />
		Password: <input type="password" name="password"/>
		<br />
		<div><input type="checkbox" name="create"> Create new account</div>
		<input type="submit" name="submit", value="OK">
	</form>
		<p><?php
			echo "$msg <br />";
			echo $_SESSION['login'];
			echo '<a href="index.php">На главную</a>';
		?></p>
</body></html>