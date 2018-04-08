<?php
	session_start();
	if (empty($_SESSION['login']))
	{
		echo '<div>You need to login or create account to use basket </div>';
		echo '<a href="log_in.php"><button type="button" class="log_in">Login</button></a>';
	}
	else
	{
		require_once('connectvars.php');
		require_once('appvars.php');
		session_start();
		$dbc = mysqli_connect(DB_HOST, DB_USER, DB_PASS, DB_NAME) 
			or die("DATA BASE CONNECTION ERROR");
		
		$query = "SELECT * FROM `products` WHERE id IN(".implode(",", $_SESSION['booking']).")";
	

		$data = mysqli_query($dbc, $query);

		$rowcount = mysqli_num_rows($data);
		if ($rowcount == 0)
			echo 'Basket is empty <br />';

		$total_price = 0;
		while ($row = mysqli_fetch_array($data))
		{
			$image_name = GW_UPLOADPATH . $row['image']; 
	
			echo '<div class="product">';
			echo '<div class="prod_img"> <img src="' . $image_name . '" alt = "product image" /> </div>';
			echo '<div class="prod_name"> <strong>Name:</strong> ' . $row['name'] . '</div>';
			echo '<div> <strong>Price</strong> ' . $row['price'] . '$</div>';
			if (in_array($row['id'], $_SESSION['booking']))
				echo '<a href="delete_from_basket2.php?prod_id=' . $row['id'] . '"><button type="button" class="basket">Delete</button></a>';
			echo '</div>';

			$total_price += $row['price'];
		}
		$_SESSION['total_price'] = $total_price;
		//print("Total price:" . $total_price . "$");
		mysqli_close($dbc);
	}
?>