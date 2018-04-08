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
						<p>MUSIC SHOW</p>
						<div></div>
						<?php
							session_start();
							if (isset($_SESSION['login']))
								echo '<p><a href="log_out.php">Log_out</a></p>';
							else
								echo '<p><a href="log_in.php">Log_in</a></p>';
						?>
						<p>Basket</p>
				</div>
			</div>

				<div class="sidebar">
					<div class="sidebar">
						<button class="category1">
							<a href="http://localhost:8100/RUSH00/index.php?category=all">All</a>
						</button>
						<button class="category1">
							<a href="http://localhost:8100/RUSH00/index.php?category=drums">drums</a>
						</button>
						<button class="category1">
							<a href="http://localhost:8100/RUSH00?category=eguitars">electric guitars</a>
						</button>
						<button class="category1">
							<a href="http://localhost:8100/RUSH00?category=aguitars">acoustic guitars</a>
						</button>
						<button class="category1">
							<a href="http://localhost:8100/RUSH00?category=synt">synthesizer</a>
						</button>
						<button class="category1">
							<a href="http://localhost:8100/RUSH00?category=sax">saxophones</a>
						</button>
					</div>
				</div>
	
			<div class="content">
			<?php
				require_once('display_content.php');
			?>
			</div>
			
		</div>
	</body>
</html>