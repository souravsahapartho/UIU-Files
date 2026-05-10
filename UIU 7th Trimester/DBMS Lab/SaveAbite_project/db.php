<?php
$host = "localhost:3307";
$user = "root";
$pass = ""; // Your MySQL password
$dbname = "saveabite";

// Establish a connection to the MySQL database
$conn = new mysqli($host, $user, $pass, $dbname);

// Check for connection errors
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>