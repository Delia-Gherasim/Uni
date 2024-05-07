<?php

$host = 'DESKTOP-G5O4MNS\SQLEXPRESS'; 
$dbname = 'temaWeb'; 

$dsn = "odbc:Driver={SQL Server};Server=$host;Database=$dbname;";

try {
    $pdo = new PDO($dsn);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    die("Error: " . $e->getMessage());
}

$category = isset($_GET['category']) ? $_GET['category'] : null;
$startDate = isset($_GET['startDate']) ? $_GET['startDate'] : null;
$endDate = isset($_GET['endDate']) ? $_GET['endDate'] : null;

$query = "SELECT * FROM News WHERE 1=1";
$params = [];
if ($category) {
    $query .= " AND category = :category";
    $params[':category'] = $category;
}
if ($startDate && $endDate) {
    $query .= " AND dateOfNews BETWEEN :startDate AND :endDate";
    $params[':startDate'] = $startDate;
    $params[':endDate'] = $endDate;
}

$stmt = $pdo->prepare($query);
$stmt->execute($params);

$result = $stmt->fetchAll(PDO::FETCH_ASSOC);
$pdo = null;

echo json_encode($result);
?>
