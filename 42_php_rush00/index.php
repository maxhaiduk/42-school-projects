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
					<div class="school42"><img src="http://www.42.fr/wp-content/themes/42/images/42_logo_black.svg" alt="42"></div>
					<div class="music_show"><p>MUSIC SHOP</p></div>
						<?php
							session_start();
							if (isset($_SESSION['login']))
								echo '<a href="log_out.php"><button type="button" class="log_in">Logout</button></a>';
							else
								echo '<a href="log_in.php"><button type="button" class="log_in">Login</button></a>';
						?>
						<a href="basket.php"><button type="button" class="basket">BASKET</button></a>
				</div>
			</div>
				<div class="sidebar">
						<a href="http://localhost:8100/RUSH00?category=all"><button class="category1">All</button></a>
						<a href="http://localhost:8100/RUSH00?category=drums"><button class="category1">drums</button></a>
						<a href="http://localhost:8100/RUSH00?category=eguitars"><button class="category1">electric guitars</button></a>
						<a href="http://localhost:8100/RUSH00?category=aguitars"><button class="category1">acoustic guitars</button></a>
						<a href="http://localhost:8100/RUSH00?category=synt"><button class="category1">synthesizer</button></a>
						<a href="http://localhost:8100/RUSH00?category=sax"><button class="category1">saxophones</button></a>
				</div>
			<div class="content">
			<?php
				require_once('display_content.php');
			?>
			</div>
			
		</div>
	</body>
</html>