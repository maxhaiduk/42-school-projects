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
						<img src="" alt="Some picture">
						<p>SOME NAME</p>
				</div>
			</div>

			<div class="sidebar">
				<div class="category1">category1</div>
				<div class="category2">category2</div>
				<div class="category3">category3</div>
				<div class="category4">category4</div>
				<div class="category5">category5</div>
			</div>
	
			<div class="content">
			<?php
				require_once('display_content.php');
			?>
			</div>
			
		</div>
	</body>
</html>