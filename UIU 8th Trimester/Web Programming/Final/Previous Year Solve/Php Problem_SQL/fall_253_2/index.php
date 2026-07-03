<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <form method="POST">
        <label for="">Items Sold</label>
        <input type="number" name="sold" id="">
        <br>
        <br>
        <label for="">Number of</label>
        <input type="number" name="numof" id="">
        <br>
        <br>
        <label for="">Target</label>
        <input type="number" name="target" id="">
        <button type="submit">Calculate</button>
    </form>


    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $sold = $_POST["sold"];
        $numof = $_POST["numof"];
        $target = $_POST["target"];

        $items = $sold * $numof;

        echo "<br>Total items: $items<br>";

        if ($items >= 500) {
            $performance = 'Excellent';
        } else if ($items >= 300 && $items < 500) {
            $performance = 'Good';
        } else if ($items >= 150 && $items < 300) {
            $performance = 'Average';
        } else {
            $performance = 'Poor';
        }

        echo "<br>Performance: $performance<br>";

        if ($items > $target) {
            $result = "Above target by " . ($items - $target);
        } else if ($items < $target) {
            $result = "Below target by " . ($target - $items);
        } else {
            $result = "Target met exactly (0)";
        }
        echo "<br>$result";
    }
    ?>
</body>

</html>