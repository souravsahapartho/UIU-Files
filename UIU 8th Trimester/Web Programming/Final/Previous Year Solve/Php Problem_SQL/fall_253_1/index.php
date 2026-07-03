<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Student Marks</title>
</head>

<body>
    <form method="POST">
        <label for="">CT1</label>
        <input type="number" name="ct1" id="">
        <br>
        <br>
        <label for="">CT2</label>
        <input type="number" name="ct2" id="">
        <br>
        <br>
        <label for="">CT3</label>
        <input type="number" name="ct3" id="">
        <br><br>
        <label for="">Midterm Marks</label>
        <input type="number" name="mid" id="">
        <br><br>
        <label for="">Final Marks</label>
        <input type="number" name="final" id="">
        <br><br>
        <button type="submit">Calculate</button>
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $ct1 = $_POST["ct1"];
        $ct2 = $_POST["ct2"];
        $ct3 = $_POST["ct3"];
        $mid = $_POST["mid"];
        $final = $_POST["final"];


        $cts = [$ct1, $ct2, $ct3];

        rsort($cts);

        $bestTwo = $cts[0] + $cts[1];

        $ctAvg = $bestTwo / 2;
        $total = $ctAvg + $mid + $final;

        $status = ($total > 54) ? "Passed" : "Failed";

        echo "<hr>";

        echo "<h3>Output</h3>";

        echo "Best two CT's total : $bestTwo <br>";
        echo " Midterm marks: $mid <br>";
        echo " final marks: $final <br>";
        echo " total marks: $total <br>";
        echo " Status: $status <br>";
    }
    ?>
</body>

</html>