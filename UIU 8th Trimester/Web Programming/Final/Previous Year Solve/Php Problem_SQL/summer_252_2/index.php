<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Movie Calculation</title>
</head>

<body>
    <h3>Wasted money of theater</h3>
    <form method="POST">
        <label for="">Attendees</label>
        <input type="number" name="att" id="">
        <br><br>
        <label for="">Seat Capacity</label>
        <input type="number" name="seat" id="">
        <br><br>
        <label for="">Ticket Price</label>
        <input type="number" name="price" id="">
        <br><br>
        <button>Calculate Cost</button>
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $attendees = $_POST["att"];
        $seat = $_POST["seat"];
        $price = $_POST['price'];


        $screen = ceil($attendees / $seat);
        $empty = ($seat * $screen) - $attendees;
        $waste = ($empty * $price);

        echo "<hr>";

        echo "<h3>Wasted Money</h3>";

        echo "total screens: $screen <br>";
        echo "empty seats: $empty <br>";
        echo "wasted money: $waste <br>";
    }
    ?>
</body>

</html>