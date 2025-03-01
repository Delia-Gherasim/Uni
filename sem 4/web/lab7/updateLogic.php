<?php
header("Access-Control-Allow-Origin: *"); 
header("Access-Control-Allow-Methods: GET, POST, OPTIONS"); 
header("Access-Control-Allow-Headers: Content-Type, Authorization, X-Requested-With");

$servername = "localhost"; 
$username = "root"; 
$password = ""; 
$dbname = "news"; 

try {
    $pdo = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $id = isset($_GET['id']) ? $_GET['id'] : null;

    if ($id) {
        $title = isset($_POST['title']) ? $_POST['title'] : '';
        $producer = isset($_POST['producer']) ? $_POST['producer'] : '';
        $category = isset($_POST['category']) ? $_POST['category'] : '';
        $date = isset($_POST['date']) ? $_POST['date'] : '';
        $text = isset($_POST['text']) ? $_POST['text'] : '';

        $query = "UPDATE news 
                  SET title = :title, 
                      producer = :producer, 
                      category = :category, 
                      date = :date, 
                      text = :text 
                  WHERE id = :id";
        
        $stmt = $pdo->prepare($query);
        $stmt->bindParam(':id', $id);
        $stmt->bindParam(':title', $title);
        $stmt->bindParam(':producer', $producer);
        $stmt->bindParam(':category', $category);
        $stmt->bindParam(':date', $date);
        $stmt->bindParam(':text', $text);

        if ($stmt->execute()) {
            echo "Update successful";
        } else {
            echo "Update failed";
        }
    } else {
        echo "No ID provided";
    }

} catch (PDOException $e) {
    echo "Error: " . $e->getMessage();
}

$pdo = null; 
?>
