<?php

$conn = mysqli_connect("localhost", "root", "", "campus_library");

if (!$conn) {
    die('Database connection failed');
}
echo "<h3>1. Query 1</h3>";

$query1 = "
select  Status,
count(*) As TotalBooks
from book_loans
group by Status
having count(*)>1
";

$result = mysqli_query($conn, $query1);


while ($row = mysqli_fetch_assoc($result)) {
    echo $row['Status'] . " = " . $row['TotalBooks'] . "<br>";
}

echo "2. Grace Period Update<br>";

$query2 = "
Update book_loans
Set Status='Grace Period',
PenaltyFee=0
Where Status='Overdue' AND DayOverdue<7
";

mysqli_query($conn, $query2);

echo "<br>Grace period updated<br>";


$query3="
Update book_loans
set PenaltyFee=<PenaltyFee class="10">
where </PenaltyFee>
"

mysqli_close($conn);
