-- ============================================================
-- ELMS Platform Full Database Schema
-- Run this in MySQL (phpMyAdmin, MySQL Workbench, Railway, etc.)
-- ============================================================

-- 1. Users Table
CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    password VARCHAR(255) NOT NULL,
    role VARCHAR(50) DEFAULT 'student',
    avatar VARCHAR(500) DEFAULT 'U',
    status VARCHAR(50) DEFAULT 'Pending',
    first_login VARCHAR(100) DEFAULT NULL,
    last_login VARCHAR(100) DEFAULT NULL
);

-- 2. Courses Table
CREATE TABLE IF NOT EXISTS courses (
    id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    description TEXT,
    category VARCHAR(100),
    difficulty VARCHAR(50),
    instructor_email VARCHAR(100),
    instructor_name VARCHAR(100),
    total_lessons INT DEFAULT 4,
    status VARCHAR(50) DEFAULT 'Pending',
    thumbnail_url VARCHAR(500) DEFAULT NULL,
    video_url VARCHAR(500) DEFAULT NULL
);

-- 3. Course Chats Table
CREATE TABLE IF NOT EXISTS course_chats (
    id INT AUTO_INCREMENT PRIMARY KEY,
    course_id VARCHAR(100) NOT NULL,
    course_name VARCHAR(255),
    user_name VARCHAR(100),
    user_email VARCHAR(100),
    message TEXT,
    `time` VARCHAR(50),
    media_url VARCHAR(500) DEFAULT NULL,
    media_type VARCHAR(50) DEFAULT NULL
);

-- 4. Enrollments Table
CREATE TABLE IF NOT EXISTS enrollments (
    id INT AUTO_INCREMENT PRIMARY KEY,
    course_id VARCHAR(100) NOT NULL,
    course_title VARCHAR(255),
    student_email VARCHAR(100),
    student_name VARCHAR(100),
    instructor_email VARCHAR(100),
    status VARCHAR(50) DEFAULT 'Pending',
    `date` VARCHAR(50)
);

-- 5. Notifications Table
CREATE TABLE IF NOT EXISTS notifications (
    id INT AUTO_INCREMENT PRIMARY KEY,
    identifier VARCHAR(100) NOT NULL,
    text TEXT NOT NULL,
    color VARCHAR(50),
    `date` VARCHAR(50),
    `time` VARCHAR(50),
    unread TINYINT(1) DEFAULT 1
);

-- 6. Feedbacks Table
CREATE TABLE IF NOT EXISTS feedbacks (
    id INT AUTO_INCREMENT PRIMARY KEY,
    course_id VARCHAR(100) NOT NULL,
    course_name VARCHAR(255),
    user_name VARCHAR(100),
    user_email VARCHAR(100),
    rating INT DEFAULT 5,
    comment TEXT,
    `date` VARCHAR(50)
);

-- 7. Complaints Table
CREATE TABLE IF NOT EXISTS complaints (
    id INT AUTO_INCREMENT PRIMARY KEY,
    course_id VARCHAR(100) NOT NULL,
    course_name VARCHAR(255),
    user_name VARCHAR(100),
    user_email VARCHAR(100),
    complaint_text TEXT NOT NULL,
    `date` VARCHAR(50)
);

-- 8. Assignments Table
CREATE TABLE IF NOT EXISTS assignments (
    id INT AUTO_INCREMENT PRIMARY KEY,
    course_id VARCHAR(100) NOT NULL,
    course_name VARCHAR(255),
    title VARCHAR(255),
    description TEXT,
    due_date VARCHAR(50),
    instructor_email VARCHAR(100),
    `date` VARCHAR(50)
);

-- 9. Assignment Submissions Table
CREATE TABLE IF NOT EXISTS assignment_submissions (
    id INT AUTO_INCREMENT PRIMARY KEY,
    assignment_id INT NOT NULL,
    assignment_title VARCHAR(255) DEFAULT NULL,
    course_id VARCHAR(100),
    course_name VARCHAR(255) DEFAULT NULL,
    student_email VARCHAR(100),
    student_name VARCHAR(100),
    submission_text TEXT,
    `date` VARCHAR(50),
    marks INT DEFAULT NULL,
    instructor_comment TEXT DEFAULT NULL
);

-- 10. Ban Requests Table
CREATE TABLE IF NOT EXISTS ban_requests (
    id INT AUTO_INCREMENT PRIMARY KEY,
    course_id VARCHAR(100),
    course_title VARCHAR(255),
    inst_email VARCHAR(100),
    inst_name VARCHAR(100),
    student_email VARCHAR(100),
    student_name VARCHAR(100),
    status VARCHAR(50) DEFAULT 'Pending',
    `date` VARCHAR(50),
    reason TEXT DEFAULT NULL
);

-- 11. Profile Pictures Table
CREATE TABLE IF NOT EXISTS profile_pictures (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100),
    user_type VARCHAR(50),
    image_link VARCHAR(500),
    uploaded_time VARCHAR(50)
);

-- 12. Module Videos Table
CREATE TABLE IF NOT EXISTS module_videos (
    id INT AUTO_INCREMENT PRIMARY KEY,
    course_id VARCHAR(100),
    module_index INT,
    video_url VARCHAR(500),
    uploaded_by VARCHAR(100),
    description TEXT DEFAULT NULL,
    duration INT DEFAULT NULL,
    UNIQUE KEY unique_module (course_id, module_index)
);

-- 13. Module Progress Table
CREATE TABLE IF NOT EXISTS module_progress (
    id INT AUTO_INCREMENT PRIMARY KEY,
    course_id VARCHAR(100),
    student_email VARCHAR(100),
    module_index INT,
    completed_at VARCHAR(100),
    UNIQUE KEY unique_progress (course_id, student_email, module_index)
);

-- 14. Chat Read Status Table
CREATE TABLE IF NOT EXISTS chat_read_status (
    id INT AUTO_INCREMENT PRIMARY KEY,
    user_email VARCHAR(100) NOT NULL,
    course_id VARCHAR(100) NOT NULL,
    last_read_message_id INT DEFAULT 0,
    UNIQUE KEY unique_user_room (user_email, course_id)
);

-- 15. Student Activity Table
CREATE TABLE IF NOT EXISTS student_activity (
    id INT AUTO_INCREMENT PRIMARY KEY,
    student_email VARCHAR(100) NOT NULL,
    activity_date DATE NOT NULL,
    UNIQUE KEY unique_activity (student_email, activity_date)
);