<?php
$host = 'DESKTOP-G5O4MNS\SQLEXPRESS'; 
$dbname = 'temaWeb'; 

$mysqli = new mysqli('DESKTOP-G5O4MNS\SQLEXPRESS', 'DESKTOP-G5O4MNS\40723', 'password', 'temaWeb');

if ($mysqli->connect_errno) {
    die("Error: " . $mysqli->connect_error);
}

$query = "SELECT DISTINCT category FROM News";
$result = $mysqli->query($query);

if (!$result) {
    die("Error: " . $mysqli->error);
}

$categories = [];
while ($row = $result->fetch_assoc()) {
    $categories[] = $row['category'];
}

$mysqli->close();

header('Content-Type: application/json'); // Set the header to indicate JSON content
echo json_encode($categories);
?>
