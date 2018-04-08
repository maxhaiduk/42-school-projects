<?php
	require_once('connectvars.php');
	require_once('appvars.php');
	$dbc = mysqli_connect(DB_HOST, DB_USER, DB_PASS, DB_NAME) 
		or die("DATA BASE CONNECTION ERROR");
	if (empty($_GET['category']) or $_GET['category'] == 'all')
		$query = "SELECT * FROM `products`";
	else
		$query = "SELECT * FROM `products` WHERE category='" . $_GET['category'] . "'";
	$data = mysqli_query($dbc, $query);
	while ($row = mysqli_fetch_array($data))
	{
		$image_name = GW_UPLOADPATH . $row['image']; 

		echo '<div class="product">';
		echo '<div class="prod_img"> <img src="' . $image_name . '" alt = "product image" /> </div>';
		echo '<div class="prod_name"> <strong>Name:</strong> ' . $row['name'] . '</div>';
		echo '<div> <strong>Price</strong> ' . $row['price'] .  '</div>';
		echo '</div>';
	}
	mysqli_close($dbc);
?>

</html>