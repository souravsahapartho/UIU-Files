<?php
include 'db.php';
header('Content-Type: application/json');
session_start();

$method = $_SERVER['REQUEST_METHOD'];
$data = json_decode(file_get_contents('php://input'), true);

if ($method == 'POST') {
    $action = $_GET['action'] ?? '';

    if ($action == 'signup') {
        $name = $conn->real_escape_string($data['name']);
        $email = $conn->real_escape_string($data['email']);
        $pass = $conn->real_escape_string($data['password']);
        $type = $conn->real_escape_string($data['user_type']);
        $zone = intval($data['zone_id']);

        $sql = "INSERT INTO users (name, email, password, user_type, zone_id) VALUES ('$name', '$email', '$pass', '$type', $zone)";
        if ($conn->query($sql)) echo json_encode(["status" => "success"]);
        else echo json_encode(["status" => "error", "message" => "Email already exists."]);
        exit;
    }

    if ($action == 'signin') {
        $email = $conn->real_escape_string($data['email']);
        $pass = $conn->real_escape_string($data['password']);
        
        $sql = "SELECT u.*, z.zone_name FROM users u LEFT JOIN zones z ON u.zone_id = z.id WHERE u.email = '$email'";
        $result = $conn->query($sql);
        
        if ($user = $result->fetch_assoc()) {
            if ($pass === $user['password']) {
                $_SESSION['user_id'] = $user['id'];
                echo json_encode(["status" => "success", "user" => $user]);
            } else echo json_encode(["status" => "error", "message" => "Invalid password."]);
        } else echo json_encode(["status" => "error", "message" => "User not found."]);
        exit;
    }

    if ($action == 'donate_money') {
        $uid = intval($data['user_id']);
        $amt = floatval($data['amount']);
        $tx = $conn->real_escape_string($data['transaction_id']);
        $conn->query("INSERT INTO monetary_donations (user_id, amount, transaction_id) VALUES ($uid, $amt, '$tx')");
        echo json_encode(["status" => "success"]);
        exit;
    }

    if ($action == 'post_food') {
        $did = intval($data['donor_id']);
        $det = $conn->real_escape_string($data['food_details']);
        $qty = $conn->real_escape_string($data['quantity']);
        $time = $conn->real_escape_string($data['pickup_deadline']);
        $otp = str_pad(rand(0, 999999), 6, '0', STR_PAD_LEFT);
        $sql = "INSERT INTO food_listings (donor_id, food_details, quantity, pickup_deadline, otp_code) VALUES ($did, '$det', '$qty', '$time', '$otp')";
        if ($conn->query($sql)) echo json_encode(["status" => "success", "otp" => $otp]);
        exit;
    }
}

if ($method == 'GET') {
    $action = $_GET['action'] ?? '';

    if ($action == 'admin_stats') {
        $money = $conn->query("SELECT SUM(amount) as total FROM monetary_donations")->fetch_assoc()['total'] ?? 0;
        $meals = $conn->query("SELECT COUNT(*) as total FROM food_listings WHERE status='Delivered'")->fetch_assoc()['total'];
        $users = $conn->query("SELECT COUNT(*) as total FROM users")->fetch_assoc()['total'];
        $txs = $conn->query("SELECT d.*, u.name FROM monetary_donations d JOIN users u ON d.user_id = u.id ORDER BY d.created_at DESC LIMIT 5");
        $recent = [];
        while ($r = $txs->fetch_assoc()) $recent[] = $r;
        echo json_encode(["money" => $money, "meals" => $meals, "users" => $users, "recent" => $recent]);
        exit;
    }

    if ($action == 'history') {
        $uid = intval($_GET['uid']);
        $res = $conn->query("SELECT f.food_details, d.status, d.end_time FROM deliveries d JOIN food_listings f ON d.listing_id = f.id WHERE d.volunteer_id = $uid ORDER BY d.start_time DESC");
        $history = [];
        while ($r = $res->fetch_assoc()) $history[] = $r;
        echo json_encode($history);
        exit;
    }

    if (isset($_GET['leaderboard'])) {
        $res = $conn->query("SELECT * FROM volunteer_stats ORDER BY green_points DESC LIMIT 10");
        $data = [];
        while ($r = $res->fetch_assoc()) $data[] = $r;
        echo json_encode($data);
        exit;
    }

    $status = $_GET['status'] ?? 'Available';

    $sql = "SELECT f.*, d_u.name as donor_name, v_u.name as volunteer_name 
            FROM food_listings f 
            JOIN users d_u ON f.donor_id = d_u.id 
            LEFT JOIN deliveries d ON f.id = d.listing_id 
            LEFT JOIN users v_u ON d.volunteer_id = v_u.id 
            WHERE f.status = '$status' 
            ORDER BY f.created_at DESC";
            
    $res = $conn->query($sql);
    $data = [];
    while ($row = $res->fetch_assoc()) {
        $data[] = $row;
    }
    echo json_encode($data);
}

if ($method == 'PUT') {
    $id = intval($_GET['id']);
    $action = $_GET['action'];

    if ($action == 'claim') {
        $uid = intval($_GET['uid']);
        $name = $conn->real_escape_string($_GET['name']);
        $conn->query("UPDATE food_listings SET status = 'Claimed' WHERE id = $id");
        $conn->query("INSERT INTO deliveries (listing_id, volunteer_id, status) VALUES ($id, $uid, 'Ongoing')");
        echo json_encode(["status" => "success"]);
    } 
    elseif ($action == 'start') {
        $conn->query("UPDATE food_listings SET status = 'In Transit' WHERE id = $id");
        echo json_encode(["status" => "success"]);
    } 
    elseif ($action == 'verify') {
        $otp = $_GET['otp'];
        $uid = intval($_GET['uid']);
        $name = $conn->real_escape_string($_GET['name']);
        
        $check = $conn->query("SELECT otp_code FROM food_listings WHERE id = $id")->fetch_assoc();
        if ($check['otp_code'] === $otp) {
            $conn->query("UPDATE food_listings SET status = 'Delivered' WHERE id = $id");
            $conn->query("UPDATE deliveries SET status = 'Completed', end_time = NOW() WHERE listing_id = $id");
            $conn->query("INSERT IGNORE INTO volunteer_stats (user_id, volunteer_name) VALUES ($uid, '$name')");
            $conn->query("UPDATE volunteer_stats SET green_points = green_points + 10, total_rescues = total_rescues + 1 WHERE user_id = $uid");
            echo json_encode(["status" => "success", "message" => "Verified! 10 Green Points awarded."]);
        } else {
            echo json_encode(["status" => "error", "message" => "Wrong OTP code."]);
        }
    } else {
        echo json_encode(["status" => "success"]);
    }
}
?>
