<?php
header("Access-Control-Allow-Origin: *"); 
header("Access-Control-Allow-Methods: GET, POST, OPTIONS"); 
header("Access-Control-Allow-Headers: Content-Type, Authorization, X-Requested-With");

session_start();
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "news";

try {
    $pdo = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $user = isset($_POST['user']) ? $_POST['user'] : null; 
    $password = isset($_POST['password']) ? $_POST['password'] : null;

    if ($user && $password) {
        $query = "SELECT 1 FROM users WHERE username = :user AND password = :password LIMIT 1"; 
        $stmt = $pdo->prepare($query);
        $stmt->bindParam(':user', $user);
        $stmt->bindParam(':password', $password); 

        $stmt->execute();
        $result = $stmt->fetch(PDO::FETCH_ASSOC); 

        if ($result){
            $_SESSION['username'] = $user; 
            echo json_encode(['success' => true, 'message' => 'Login successful']);
        } else {
            
            echo json_encode(['success' => false, 'message' => 'Invalid username or password']);
        }
    } else {
        echo json_encode(['error' => 'Missing user or password']); 
    }

} catch (PDOException $e) {
    echo json_encode(['error' => 'Database error: ' . $e->getMessage()]); 
}

$pdo = null;
?>
