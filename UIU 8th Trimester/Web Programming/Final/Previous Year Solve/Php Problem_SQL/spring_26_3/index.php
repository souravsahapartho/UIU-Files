<?php

$conn = mysqli_connect("localhost", "root", "", "campus_library");

if (!$conn) {
    die("Database connection failed");
}

echo "<h2>1. Total Number of Books for Each Status</h2>";

$query1 = "
SELECT Status,
COUNT(*) AS TotalBooks
FROM book_loans
GROUP BY Status
HAVING COUNT(*) > 1
";

$result1 = mysqli_query($conn,$query1);

while($row=mysqli_fetch_assoc($result1))
{
    echo $row['Status']." = ".$row['TotalBooks']."<br>";
}

echo "<hr>";


$query2 = "
UPDATE book_loans
SET Status='Grace Period',
PenaltyFee=0
WHERE Status='Overdue'
AND DaysOverdue<7
";

mysqli_query($conn,$query2);

echo "Updated Successfully";

echo "<hr>";


$query3 = "
UPDATE book_loans
SET PenaltyFee=PenaltyFee*1.10
WHERE PenaltyFee>20
AND PenaltyFee*1.10<=50
";

mysqli_query($conn,$query3);

echo "Processing Charge Added Successfully";

echo "<hr>";


echo "<h2>4. Book Title and Total Penalty Fee</h2>";

$query4 = "
SELECT BookTitle,
SUM(PenaltyFee) AS TotalPenalty
FROM book_loans
GROUP BY BookTitle
ORDER BY TotalPenalty DESC
";

$result4 = mysqli_query($conn,$query4);

echo "<table border='1' cellpadding='8'>";

echo "
<tr>
<th>Book Title</th>
<th>Total Penalty</th>
</tr>
";

while($row=mysqli_fetch_assoc($result4))
{
    echo "
    <tr>
        <td>{$row['BookTitle']}</td>
        <td>{$row['TotalPenalty']}</td>
    </tr>
    ";
}

echo "</table>";

mysqli_close($conn);

?>