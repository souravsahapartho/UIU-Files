<?php

$conn = mysqli_connect("localhost", "root", "", "sundarban1");

if (!$conn) {
    die("Database connection failed");
}


echo "<h2>1. Total Revenue Per Category</h2>";

$query1 = "
SELECT CategoryName,
SUM(Revenue) AS TotalRevenue
FROM sales_data
GROUP BY CategoryName
";

$result1 = mysqli_query($conn, $query1);

while ($row = mysqli_fetch_assoc($result1)) {
    echo $row['CategoryName'] . " = " . $row['TotalRevenue'] . "<br>";
}

echo "<hr>";


$query2 = "
UPDATE sales_data
SET CategoryName='Low Performing'
WHERE Revenue<40000
";

mysqli_query($conn, $query2);

echo "<h2>2. Grace Period Updated</h2>";


echo "Updated Successfully";

echo "<hr>";


$query3 = "
UPDATE sales_data
SET Revenue=Revenue*1.10
WHERE Revenue>70000
";

mysqli_query($conn, $query3);

echo "<h2>3. Processing Charge Added</h2>";


echo "Bonus Added Successfully";

echo "<hr>";


echo "<h2>4. Product Status</h2>";

$query4 = "
SELECT ProductName,
CategoryName,

CASE
WHEN Revenue >
(
SELECT AVG(s2.Revenue)
FROM sales_data s2
WHERE s2.CategoryID=s1.CategoryID
)

THEN 'Top Seller'

ELSE 'Regular Seller'

END AS Label

FROM sales_data s1
";

$result4 = mysqli_query($conn, $query4);

echo "<table border='1' cellpadding='8'>";

echo "
<tr>
<th>Product</th>
<th>Category</th>
<th>Status</th>
</tr>
";

while ($row = mysqli_fetch_assoc($result4)) {
    echo "
    <tr>
        <td>{$row['ProductName']}</td>
        <td>{$row['CategoryName']}</td>
        <td>{$row['Label']}</td>
    </tr>
    ";
}

echo "</table>";

mysqli_close($conn);
