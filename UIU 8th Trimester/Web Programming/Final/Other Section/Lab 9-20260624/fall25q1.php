<!DOCTYPE html>
<html lang="en">
<body>
    <form action="" method="post">
        CT1: <input type="text" name="ct1"> <br>
        CT2: <input type="text" name="ct2"> <br>
        CT3: <input type="text" name="ct3"> <br>
        Mid: <input type="text" name="mid"> <br>
        Final: <input type="text" name="final"> <br>

        <button name="submit">Submit</button>
    </form>

    
    <?php
        if(isset($_POST["submit"])){
            $ct1 = $_POST["ct1"];
            $ct2 = $_POST["ct2"];
            $ct3 = $_POST["ct3"];
            $mid = $_POST["mid"];
            $final = $_POST["final"];

            $bestTwoAvg = (($ct1+$ct2+$ct3) - min($ct1,$ct2,$ct3))/2;

            $total = $bestTwoAvg+$final+$mid;
            if($total <54)
                $status = "Failed";
            else 
                $status = "Passed";

            echo "CTs avg ". $bestTwoAvg. "<br>";
            echo "Mid ". $mid. "<br>";
            echo "Final ". $final. "<br>";
            
            echo "Total ". $total. "<br>";
            echo "Status ". $status;
            
        }

    ?>


    <!-- code for table creation, not a part of the solution of fall25 question -->
    <form action="" method="post">
        Number: <input type="text" name="number"><br>
        <button name="submit1">Submit</button> <br>
    </form>
    
    <?php
        if(isset($_POST["submit1"])){
            $number = $_POST["number"];

            echo "<table border='1'>";
            for ($i = 1; $i<=$number; $i++){
                echo "<tr>";
                    for ($j = 1; $j<=$number; $j++){
                        echo "<td style='color:red'> $i $j </td>";
                    }
                echo "</tr>";
            }

            echo "</table>";

        }
    ?>

    <table>
        <tr>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <td></td>
            <td></td>
            <td></td>
        </tr>
    </table>
</body>
</html>