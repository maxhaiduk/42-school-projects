<?php
    require_once('connectvars.php');
    require_once('appvars.php');
    session_start();
    
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
        echo '<div class="prod_info">';
        echo '<div class="prod_name">' . $row['name'] . '</div>';
        echo '<div class="prod_price">' . $row['price'] . '$</div>';
        echo '</div>';
        if (!in_array($row['id'], $_SESSION['booking']))
            echo '<a href="add_to_basket.php?category=' . $_GET['category'] . '&prod_id=' . $row['id'] . '"><button type="basket" class="prod_button">Add to basket</button></a>';
        if (in_array($row['id'], $_SESSION['booking']))
            echo '<a href="delete_from_basket.php?category=' . $_GET['category'] . '&prod_id=' . $row['id'] . '"><button type="basket" class="prod_button">Delete from basket</button></a>';
        echo '</div>';
    }
    mysqli_close($dbc);
?>
</html>