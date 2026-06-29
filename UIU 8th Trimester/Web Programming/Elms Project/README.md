# 🎓 ELMS - Educational Learning Management System

A comprehensive, full-stack Educational Learning Management System built with a lightweight Vanilla JS frontend and a robust Express/MySQL backend. It features a complete role-based architecture (**Admin, Instructor, Student**) with seamless database-driven course management, interactive assignments, and a real-time WhatsApp-style global chat system powered by Cloudinary.

---

## 🚀 Dynamic & Implemented Features

### 🔐 Authentication & Authorization

* **Role-Based Access Control (RBAC):** Three strictly isolated roles ensuring secure routing for Admins, Instructors, and Students.


* **Database-Driven Approval System:** New student and instructor accounts are marked as 'Pending' in the database and require manual Admin approval to access the dashboard.


* **Account Security:** Secure password hashing (SHA-256) implementation and frontend session management via Local Storage, alongside First and Last Login tracking.


* **Account Suspension:** Admins can dynamically suspend (Ban) or restore (Approve) user accounts, revoking or granting access instantly.


* **Account Deletion:** Users have full control to permanently delete their accounts and associated data.



### 🎨 General & UI/UX Features

* **Modern Responsive UI:** Built with a custom Tailwind-inspired CSS structure for seamless mobile and desktop experiences.


* **Persistent Dark/Light Mode:** User preference is saved dynamically in Local Storage and applied instantly across all dashboard views.


* **Cloudinary Profile Management:** Users can upload profile pictures directly to Cloudinary (up to 5MB, JPG/PNG), automatically updating their avatar across the dashboard and chat interfaces.


* **Dynamic Notification System:** Real-time, database-driven notifications (with unread badges) triggered by events like course approvals, enrollment updates, graded assignments, and administrative actions.



### 👨‍🎓 Student Features

* **Dynamic Dashboard:** Fetches and displays actual enrolled courses, pending assignments, and learning statistics directly from the database.


* **Progress & Streak Tracking:** Monitors daily activity to calculate learning streaks, total active hours per month, and overall course completion percentages.


* **Course Browsing & Enrollment:** Explore all admin-approved courses and send enrollment join requests to instructors.


* **Course Player:** Stream functional course videos via Cloudinary URLs with dynamically generated lesson modules based on the course's total lesson count.


* **Assignment Hub:** Submit assignment texts or document links, and view real-time grades out of 10 alongside instructor feedback.


* **Feedback & Complaints:** Submit 1 to 5-star ratings and text reviews (stored in the feedbacks table) and send direct, private complaints to the Admin.



### 👨‍🏫 Instructor Features

* **Live Analytics:** Real-time tracking of active published courses, total enrolled students, and pending enrollment requests.


* **Media-Rich Course Creation:** Upload course details alongside cover thumbnails and video lectures, safely stored and categorized in Cloudinary folders.


* **Advanced Module Management:** Upload individual module videos, replace existing content, delete outdated videos, and add detailed text descriptions for each lesson.


* **Course Editing:** Fully dynamic course updating, allowing modifications to titles, descriptions, categories, and media files without losing student progress.


* **Enrollment Management:** Accept or reject student join requests, triggering automated notifications to the student.


* **Student Tracking:** View an active list of enrolled students tied to your courses, complete with their enrollment dates and individual progress metrics.


* **Ban Requests:** Submit formal requests to the Admin, including a required reason, to ban or remove specific disruptive students from a course.


* **Assignment Management & Grading:** Create new assignments with specific due dates, review student submissions, and assign scores (0-10) with custom feedback.



### 👑 Admin Features

* **Centralized Analytics:** Database queries dynamically calculate Total Users, Total Courses, Active Students, and Pending Actions.


* **User Management System:** Filter users by status (All, Pending, Approved, Banned) and execute one-click approvals, suspensions, or account restorations.


* **Course Moderation:** Review newly uploaded courses. Approving a course makes it visible to all students and sends a platform-wide notification, while the Unpublish feature temporarily hides active courses.


* **Ban Request Handling:** Approve or reject instructor-initiated ban requests. Approving automatically removes the student from the course list and notifies all relevant parties.


* **Activity & Complaint Log:** A dedicated timeline displaying all recent platform activity, administrative actions, and a unified view of all course complaints submitted by users.



### 💬 Advanced Global Chat System

* **Floating Chat Widget:** A globally accessible, WhatsApp-style interface with a polling-based unread message badge that tracks read status per user.


* **Role-Specific Automated Groups:** Students only see chat groups for courses they are officially enrolled in.


* **Instructor Visibility:** Instructors automatically see chat groups for the courses they have published.


* **Admin Targeted Broadcasts:** A dedicated "Official Announcements" channel where Admins can broadcast messages dynamically to All Platform Users, Students Only, or Instructors Only.


* **Read-Only Mode:** The broadcast channel intelligently disables input for standard users, keeping it strictly for official announcements.


* **Cloudinary Media Sharing:** Users can attach and upload Images and Videos directly into the chat stream with instant visual previews.


* **Smart UI Integration:** Chats feature auto-scroll, formatted date/time stamps, message deletion capabilities for authors/admins, and special 👑 Admin badges for administrative messages.



---

## 🛠️ Tech Stack

* **Frontend:** HTML5, Custom CSS, Vanilla JavaScript.


* **Backend:** Node.js, Express.js.


* **Database:** MySQL (utilizing `mysql2` connection pooling).


* **Media Storage:** Cloudinary (Organized into specific folders: `course_videos`, `profile_pics`, `chat_media`, and `course_images`).


* **File Processing:** Multer & Multer-Storage-Cloudinary for seamless buffer-to-cloud streaming.



---

## 🗄️ Database Architecture

The system utilizes a highly relational MySQL structure with 15 dedicated tables to manage platform data securely:

* `users` - Core authentication and profile data.


* `courses` - Metadata, status, and media links for all educational content.


* `enrollments` - Tracks the relationship and approval status between students and courses.


* `module_videos` - Stores individual lesson data, descriptions, and durations.


* `module_progress` - Logs specific timestamps when a student completes a module.


* `assignments` - Instructor-created tasks with due dates.


* `assignment_submissions` - Student answers, instructor grades, and feedback comments.


* `course_chats` - Messages, media URLs, and timestamps for all communication channels.


* `chat_read_status` - Tracks the last read message ID per user per room for unread badges.


* `notifications` - System-wide alerts with read/unread flags and color coding.


* `feedbacks` - Course ratings and reviews from students.


* `complaints` - Direct issue reporting to administration.


* `ban_requests` - Instructor submissions detailing reasons for student removal.


* `student_activity` - Daily login and activity logs used to calculate learning streaks.


* `profile_pictures` - Historical log of uploaded user avatars.



---

## 💻 Installation & Setup

### Prerequisites

* Node.js installed.
* MySQL installed and running.
* A Cloudinary account for media storage credentials.

### 1. Clone the Repository

```bash
git clone https://github.com/souravsahapartho/uiu-learning-management-system-lms-.git
cd uiu-learning-management-system-lms-
cd Backend

```

### 2. Install Dependencies

```bash
npm install

```

### 3. Environment Configuration

Create a `.env` file in the root of the `Backend` directory and add your specific credentials:

```env
PORT=5005
MYSQLHOST=your_mysql_host
MYSQLUSER=your_mysql_user
MYSQLPASSWORD=your_mysql_password
MYSQLDATABASE=your_database_name
MYSQLPORT=3306

CLOUDINARY_CLOUD_NAME=your_cloudinary_cloud_name
CLOUDINARY_API_KEY=your_cloudinary_api_key
CLOUDINARY_API_SECRET=your_cloudinary_api_secret

```

### 4. Run the Server

The `server.js` file includes initialization scripts that will automatically create all necessary tables and columns upon booting.

```bash
npm start

```

### 5. Launch the Frontend

Open the `index.html` file located in the `Frontend` directory using any local server (e.g., VS Code Live Server) to access the application.

### 6. Admin Credentials

To access the Admin dashboard and test administrative features, use the following default credentials:

* **Email:** admin@uiu.com
* **Password:** admin123

---

**Developed By:** Sourav, Supty, Jannat, Binoy

*United International University*
