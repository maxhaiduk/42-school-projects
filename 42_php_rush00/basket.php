<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<title>MUSIC_BOX</title>
		<link rel="stylesheet" type="text/css" href="styles/style.css" >
	</head>
	<body>
		<div class="grid-container">

			<div class="header">
				<div class="header_content">
						<p>MUSIC SHOP: Basket</p>
						<div></div>
						<?php
							session_start();
							if (isset($_SESSION['login']))
								echo '<a href="log_out.php"><button type="button" class="log_in">Logout</button></a>';
							else
								echo '<a href="log_in.php"><button type="button" class="log_in">Login</button></a>';
						?>
						<a href="index.php"><button type="button" class="basket">Home Page</button></a>
				</div>
			</div>
				<div class="sidebar">
					<?php echo '<p> Total price:' .$_SESSION['total_price'] .'$</p>'; ?>
					<a href=""><button type="button">Buy!</button></a>
				</div>
			<div class="content">
			<?php
				require_once('display_basket.php');
			?>
			</div>
			
		</div>
	</body>
</html>