<!DOCTYPE html>
<html>

<head>
    <title>Employee Report</title>
</head>

<body>

    <?php

    $conn = new mysqli(
        "localhost",
        "root",
        "",
        "spring_25_3"
    );

    if ($conn->connect_error) {
        die("Connection Failed");
    }

    echo "<h2>Employee Analysis</h2>";


    echo "<h3>1. Employee Count by Rating</h3>";

    $sql1 = "
SELECT PerformanceRating,
COUNT(*) AS total
FROM employee_final
GROUP BY PerformanceRating
";

    $result = $conn->query($sql1);

    while ($row = $result->fetch_assoc()) {

        echo "Rating "
            . $row["PerformanceRating"] .
            " = " .
            $row["total"] .
            "<br>";
    }


    $sql2 = "

UPDATE employee_final

SET PerformanceRating='C'

WHERE Salary<40000

AND PerformanceRating!='D'

";

    $conn->query($sql2);

    echo "<h3>2. Rating Updated</h3>";


    $sql3 = "

UPDATE employee_final

SET Salary=Salary+5000

WHERE Salary>50000

AND Salary+5000<60000

";

    $conn->query($sql3);

    echo "<h3>3. Bonus Added</h3>";


    echo "<h3>4. Department Employee Count</h3>";

    $sql4 = "

SELECT
DepartmentName,
COUNT(*) total

FROM employee_final

GROUP BY DepartmentName

ORDER BY total DESC

";

    $result2 = $conn->query($sql4);

    while ($row = $result2->fetch_assoc()) {

        echo
        $row["DepartmentName"] .
            " → " .
            $row["total"] .
            " Employee(s)<br>";
    }


    //Final Table

    echo "<h3>Updated Employee Table</h3>";

    $data = $conn->query(
        "SELECT * FROM employee_final"
    );

    echo "<table border='1'>";

    echo "
<tr>
<th>ID</th>
<th>Name</th>
<th>Department</th>
<th>Salary</th>
<th>Rating</th>
</tr>";

    while ($r = $data->fetch_assoc()) {

        echo "<tr>";

        echo "<td>" . $r["EmployeeID"] . "</td>";

        echo "<td>" . $r["EmployeeName"] . "</td>";

        echo "<td>" . $r["DepartmentName"] . "</td>";

        echo "<td>" . $r["Salary"] . "</td>";

        echo "<td>" . $r["PerformanceRating"] . "</td>";

        echo "</tr>";
    }

    echo "</table>";

    $conn->close();

    ?>

</body>

</html>