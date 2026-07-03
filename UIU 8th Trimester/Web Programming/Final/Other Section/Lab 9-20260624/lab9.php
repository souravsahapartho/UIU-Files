<!DOCTYPE html>
<html>
<body>
    <h1>This heading is from HTML</h1>

    <form action="" method="post">
        Name: <input type="text" name="name"><br>
        Email: <input type="email" name="email"> <br>
        <button name="submit">Submit</button> <br>
    </form>


    <?php
        echo "Hello world";
        echo "<h1>This heading is from PHP</h1>";
        $name = "Mahmudul Hasan Hasan";
        $cg = 3.85;
        echo "My name is ".$name. " and my cg is ". $cg;
        echo "<br>";
        echo "My name is $name and my cg is $cg <br>";

        function sum($a, $b){
            return $a+$b;
        }

        echo sum(8,7);
        echo "<br>";

        $marks = 67;
        if($marks <55)
            echo "Failed <br>";
        else
            echo "Passed <br>";

        for ($i = 1; $i<=5; $i++)
            echo "Iteration $i ";
        echo "<br>";

        // $name = str_replace("Hasan", "Hossain", $name);
        // echo $name;

        $student = [
            "name" => "Mahmudul",
            "cg" => 3.85,
            "id" => "Batch 18"
        ];

        echo $student["id"] . "<br>";
        // echo "My id is $student[id]";

        if(isset($_POST["submit"])){
            $name = $_POST["name"];
            $email = $_POST["email"];

            echo "$name $email <br>";
        }

        

    ?>
</body>
</html>