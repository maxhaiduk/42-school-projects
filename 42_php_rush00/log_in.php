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
            $query = " INSERT INTO 
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
<html>
    <head>
        <link rel="stylesheet" type="text/css" href="styles/login.css" >
    </head>   
    <body>
    <p class="back_to"><?php
            echo $_SESSION['login'];
            echo '<a href="index.php">
            <button type="button" class="back">
            Back
            </button>
            </a>';
        ?></p>
    <form class="container" method="POST" action="log_in.php">
        <h2>Input Form</h2>
        <div class="input_data">
            <label>Username:</label>
            <input type="text" name="login"/>
        </div>
        <div class="input_data">
            <label>Password:</label> 
            <input type="password" name="password"/>
        </div>
        <div class="confirm">
            <input type="checkbox" name="create" class="checkbox"> 
            <p>Create new account</p>
            <input type="submit" name="submit" class="submit", value="OK">
        </div>
        </form>
</body></html>