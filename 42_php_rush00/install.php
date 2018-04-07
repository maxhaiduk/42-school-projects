<?php
    require_once('connectvars.php');
	$sql = mysqli_connect(DB_HOST, DB_USER, DB_PASS)
			or die("DATA BASE CONNECTION ERROR\n");
    mysqli_query($sql, 'CREATE DATABASE IF NOT EXISTS music_shop');
    $sql = mysqli_connect(DB_HOST, DB_USER, DB_PASS, DB_NAME);
    $sql_content = file_get_contents(DB_NAME.'.sql');
    mysqli_multi_query($sql, $sql_content);
?>