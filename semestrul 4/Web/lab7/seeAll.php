<?php
$servername = "localhost"; 
$username = "root"; 
$password = ""; 
$dbname = "news"; 

try {
    $pdo = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $category = isset($_GET['category']) ? $_GET['category'] : null;
    $startDate = isset($_GET['startDate']) ? $_GET['startDate'] : null;
    $endDate = isset($_GET['endDate']) ? $_GET['endDate'] : null;

    $query = "SELECT * FROM news WHERE 1=1";
    $params = [];

    if ($category && $category !== '') {
        $query .= " AND category = :category";
        $params[':category'] = $category;
    }
    if ($category == '' && $category){
         $query = "SELECT * FROM news WHERE 1=1";
        $params = [];
    }
    if (!is_null($startDate) && !is_null($endDate)) {
        $query .= " AND date BETWEEN :startDate AND :endDate";
        $params[':startDate'] = $startDate;
        $params[':endDate'] = $endDate;
    }
    $stmt = $pdo->prepare($query);
    $stmt->execute($params);

    $result = $stmt->fetchAll(PDO::FETCH_ASSOC);
    echo json_encode($result);
} catch (PDOException $e) {
    echo "Error: " . $e->getMessage();
}

$pdo = null;
?>
