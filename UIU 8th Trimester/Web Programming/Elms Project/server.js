const express = require("express");
const mysql = require("mysql2");
const cors = require("cors");
const crypto = require("crypto");
const multer = require("multer");
const { v2: cloudinary } = require("cloudinary");
const { CloudinaryStorage } = require("multer-storage-cloudinary");

require("dotenv").config();

const app = express();

process.on("uncaughtException", (err) =>
  console.error("Server Error:", err.message),
);
process.on("unhandledRejection", (reason) =>
  console.error("Promise Error:", reason),
);

app.use(cors({ origin: "*" }));
app.use(express.json());

app.use((req, res, next) => {
  console.log(
    `➡️ [${new Date().toLocaleTimeString()}] ${req.method} ${req.url}`,
  );
  next();
});

const hashPassword = (password) => {
  return crypto.createHash("sha256").update(String(password)).digest("hex");
};

cloudinary.config({
  cloud_name: process.env.CLOUDINARY_CLOUD_NAME,
  api_key: process.env.CLOUDINARY_API_KEY,
  api_secret: process.env.CLOUDINARY_API_SECRET,
});

const storage = new CloudinaryStorage({
  cloudinary: cloudinary,
  params: async (req, file) => {
    if (file.mimetype.includes("video")) {
      return {
        folder: "elms/course_videos",
        resource_type: "video",
        allowed_formats: ["mp4", "webm", "mov", "mkv"],
      };
    } else if (file.fieldname === "profilePic") {
      return {
        folder: "elms/profile_pics",
        resource_type: "image",
        allowed_formats: ["jpg", "png", "jpeg", "webp"],
      };
    } else if (file.fieldname === "media" || file.mimetype.includes("image")) {
      return {
        folder: "elms/chat_media",
        resource_type: "auto",
        allowed_formats: ["jpg", "png", "jpeg", "webp", "mp4", "webm"],
      };
    } else {
      return {
        folder: "elms/course_images",
        resource_type: "image",
        allowed_formats: ["jpg", "png", "jpeg", "webp"],
      };
    }
  },
});

const upload = multer({ storage: storage });

const db = mysql.createPool({
  host: process.env.MYSQLHOST,
  user: process.env.MYSQLUSER,
  password: process.env.MYSQLPASSWORD,
  database: process.env.MYSQLDATABASE,
  port: process.env.MYSQLPORT,
  waitForConnections: true,
  connectionLimit: 10,
  queueLimit: 0,
});

db.query("SELECT 1", (err) => {
  if (err) {
    console.error("Database connection failed:", err.message);
  } else {
    console.log("Database connected.");
  }
});

const tableQueries = [
  `CREATE TABLE IF NOT EXISTS users (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(100), email VARCHAR(100) UNIQUE, password VARCHAR(255), role VARCHAR(50) DEFAULT 'student', avatar VARCHAR(500) DEFAULT 'U', status VARCHAR(50) DEFAULT 'Pending')`,
  `CREATE TABLE IF NOT EXISTS courses (id INT AUTO_INCREMENT PRIMARY KEY, title VARCHAR(255), description TEXT, category VARCHAR(100), difficulty VARCHAR(50), instructor_email VARCHAR(100), instructor_name VARCHAR(100), total_lessons INT DEFAULT 4, status VARCHAR(50) DEFAULT 'Pending', thumbnail_url VARCHAR(500) DEFAULT NULL, video_url VARCHAR(500) DEFAULT NULL)`,
  `CREATE TABLE IF NOT EXISTS course_chats (id INT AUTO_INCREMENT PRIMARY KEY, course_id VARCHAR(100) NOT NULL, course_name VARCHAR(255), user_name VARCHAR(100), user_email VARCHAR(100), message TEXT, \`time\` VARCHAR(50), media_url VARCHAR(500) DEFAULT NULL, media_type VARCHAR(50) DEFAULT NULL)`,
  `CREATE TABLE IF NOT EXISTS enrollments (id INT AUTO_INCREMENT PRIMARY KEY, course_id VARCHAR(100), course_title VARCHAR(255), student_email VARCHAR(100), student_name VARCHAR(100), instructor_email VARCHAR(100), status VARCHAR(50) DEFAULT 'Pending', \`date\` VARCHAR(50))`,
  `CREATE TABLE IF NOT EXISTS notifications (id INT AUTO_INCREMENT PRIMARY KEY, identifier VARCHAR(100), text TEXT, color VARCHAR(50), \`date\` VARCHAR(50), \`time\` VARCHAR(50), unread TINYINT(1) DEFAULT 1)`,
  `CREATE TABLE IF NOT EXISTS feedbacks (id INT AUTO_INCREMENT PRIMARY KEY, course_id VARCHAR(100) NOT NULL, course_name VARCHAR(255), user_name VARCHAR(100), user_email VARCHAR(100), rating INT, comment TEXT, \`date\` VARCHAR(50))`,
  `CREATE TABLE IF NOT EXISTS complaints (id INT AUTO_INCREMENT PRIMARY KEY, course_id VARCHAR(100) NOT NULL, course_name VARCHAR(255), user_name VARCHAR(100), user_email VARCHAR(100), complaint_text TEXT, \`date\` VARCHAR(50))`,
  `CREATE TABLE IF NOT EXISTS assignments (id INT AUTO_INCREMENT PRIMARY KEY, course_id VARCHAR(100) NOT NULL, title VARCHAR(255), description TEXT, due_date VARCHAR(50), instructor_email VARCHAR(100), \`date\` VARCHAR(50), course_name VARCHAR(255) DEFAULT NULL)`,
  `CREATE TABLE IF NOT EXISTS assignment_submissions (id INT AUTO_INCREMENT PRIMARY KEY, assignment_id INT NOT NULL, course_id VARCHAR(100), student_email VARCHAR(100), student_name VARCHAR(100), submission_text TEXT, \`date\` VARCHAR(50), marks INT DEFAULT NULL, instructor_comment TEXT DEFAULT NULL, course_name VARCHAR(255) DEFAULT NULL, assignment_title VARCHAR(255) DEFAULT NULL)`,
  `CREATE TABLE IF NOT EXISTS ban_requests (id INT AUTO_INCREMENT PRIMARY KEY, course_id VARCHAR(100), course_title VARCHAR(255), inst_email VARCHAR(100), inst_name VARCHAR(100), student_email VARCHAR(100), student_name VARCHAR(100), status VARCHAR(50) DEFAULT 'Pending', \`date\` VARCHAR(50))`,
  `CREATE TABLE IF NOT EXISTS profile_pictures (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(100), email VARCHAR(100), user_type VARCHAR(50), image_link VARCHAR(500), uploaded_time VARCHAR(50))`,
  `CREATE TABLE IF NOT EXISTS module_videos (id INT AUTO_INCREMENT PRIMARY KEY, course_id VARCHAR(100), module_index INT, video_url VARCHAR(500), uploaded_by VARCHAR(100), UNIQUE KEY unique_module (course_id, module_index))`,
  `CREATE TABLE IF NOT EXISTS module_progress (
  id INT AUTO_INCREMENT PRIMARY KEY,
  course_id VARCHAR(100),
  student_email VARCHAR(100),
  module_index INT,
  completed_at VARCHAR(100),
  UNIQUE KEY unique_progress (course_id, student_email, module_index)
)`,
  `CREATE TABLE IF NOT EXISTS chat_read_status (
  id INT AUTO_INCREMENT PRIMARY KEY,
  user_email VARCHAR(100) NOT NULL,
  course_id VARCHAR(100) NOT NULL,
  last_read_message_id INT DEFAULT 0,
  UNIQUE KEY unique_user_room (user_email, course_id)
)`,
  `CREATE TABLE IF NOT EXISTS student_activity (
  id INT AUTO_INCREMENT PRIMARY KEY,
  student_email VARCHAR(100) NOT NULL,
  activity_date DATE NOT NULL,
  UNIQUE KEY unique_activity (student_email, activity_date)
)`,
];

tableQueries.forEach((query) => {
  db.query(query, (err) => {
    if (err) console.error("Table initialization error:", err.message);
  });
});

const alterQueries = [
  "ALTER TABLE courses ADD COLUMN total_lessons INT DEFAULT 4",
  "ALTER TABLE courses ADD COLUMN thumbnail_url VARCHAR(500) DEFAULT NULL",
  "ALTER TABLE courses ADD COLUMN video_url VARCHAR(500) DEFAULT NULL",
  "ALTER TABLE users MODIFY COLUMN avatar VARCHAR(500) DEFAULT 'U'",
  "ALTER TABLE course_chats ADD COLUMN media_url VARCHAR(500) DEFAULT NULL",
  "ALTER TABLE course_chats ADD COLUMN media_type VARCHAR(50) DEFAULT NULL",
  "ALTER TABLE assignment_submissions ADD COLUMN course_name VARCHAR(255) DEFAULT NULL",
  "ALTER TABLE assignment_submissions ADD COLUMN assignment_title VARCHAR(255) DEFAULT NULL",
  "ALTER TABLE users ADD COLUMN first_login VARCHAR(100) DEFAULT NULL",
  "ALTER TABLE users ADD COLUMN last_login VARCHAR(100) DEFAULT NULL",
  "ALTER TABLE module_videos ADD COLUMN description TEXT DEFAULT NULL",
  "ALTER TABLE module_videos ADD COLUMN duration INT DEFAULT NULL",
  "ALTER TABLE ban_requests ADD COLUMN reason TEXT DEFAULT NULL",
];
alterQueries.forEach((query) => {
  db.query(query, (err) => {
    if (
      err &&
      err.code !== "ER_DUP_FIELDNAME" &&
      !err.message.includes("already exists")
    ) {
    }
  });
});

app.get("/", (req, res) => res.json({ message: "Backend API is active." }));

app.post(
  "/upload-profile-pic",
  (req, res, next) => {
    const uploadMiddleware = upload.single("profilePic");

    uploadMiddleware(req, res, (err) => {
      if (err) {
        console.error("Profile upload error:", err.message);
        return res
          .status(500)
          .json({ error: "File upload failed: " + err.message });
      }
      next();
    });
  },
  (req, res) => {
    if (!req.file) {
      return res.status(400).json({ error: "No image file uploaded." });
    }
    const imageUrl = req.file.path;
    const { name, email, role } = req.body;
    const uploadedTime = new Date().toLocaleString();

    db.query(
      "INSERT INTO profile_pictures (name, email, user_type, image_link, uploaded_time) VALUES (?, ?, ?, ?, ?)",
      [name || "", email || "", role || "", imageUrl, uploadedTime],
      (err) => {
        if (err) console.error("Profile picture save error:", err.message);
        res.status(200).json({
          message: "Profile picture uploaded successfully",
          url: imageUrl,
        });
      },
    );
  },
);

app.post(
  "/upload-chat-media",
  (req, res, next) => {
    const uploadMiddleware = upload.single("media");
    uploadMiddleware(req, res, (err) => {
      if (err) {
        console.error("Chat media upload error:", err.message);
        return res
          .status(500)
          .json({ error: "File upload failed: " + err.message });
      }
      next();
    });
  },
  (req, res) => {
    if (!req.file) {
      return res.status(400).json({ error: "No media file uploaded." });
    }
    res.status(200).json({ url: req.file.path, type: req.file.mimetype });
  },
);

app.post("/signup", (req, res) => {
  const { name, email, password, role, avatar } = req.body;
  const encryptedPassword = hashPassword(password || "");
  db.query(
    "INSERT INTO users (name, email, password, role, avatar, status) VALUES (?, ?, ?, ?, ?, 'Pending')",
    [
      name || "",
      email || "",
      encryptedPassword,
      role || "student",
      avatar || "U",
    ],
    (err) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json({ message: "Success" }),
  );
});

app.post("/login", (req, res) => {
  const { email, password } = req.body;
  const encryptedPassword = hashPassword(password || "");
  db.query(
    "SELECT * FROM users WHERE email = ? AND (password = ? OR password = ?)",
    [email || "", encryptedPassword, password || ""],
    (err, data) => {
      if (err) return res.status(500).json({ error: err.message });
      if (data.length > 0) {
        const user = data[0];
        delete user.password;
        if (user.status === "Banned") {
          return res.status(403).json({
            error:
              "Account Suspended: Your account has been suspended by the administrator.",
          });
        }
        const now = new Date().toLocaleString("en-US", {
          month: "short",
          day: "numeric",
          year: "numeric",
          hour: "2-digit",
          minute: "2-digit",
          timeZone: "Asia/Dhaka",
        });
        const updateFields = user.first_login
          ? "last_login = ?"
          : "first_login = ?, last_login = ?";
        const updateValues = user.first_login
          ? [now, email]
          : [now, now, email];
        db.query(
          `UPDATE users SET ${updateFields} WHERE email = ?`,
          updateValues,
          () => {
            user.last_login = now;
            if (!user.first_login) user.first_login = now;
            res.status(200).json({ user });
          },
        );
      } else {
        res.status(401).json({ error: "Invalid email or password" });
      }
    },
  );
});

app.put("/update-profile", async (req, res) => {
  const { name, avatar, email } = req.body;
  try {
    const promiseDb = db.promise();
    await promiseDb.query(
      "UPDATE users SET name = ?, avatar = ? WHERE email = ?",
      [name, avatar, email],
    );
    await promiseDb.query(
      "UPDATE courses SET instructor_name = ? WHERE instructor_email = ?",
      [name, email],
    );
    await promiseDb.query(
      "UPDATE enrollments SET student_name = ? WHERE student_email = ?",
      [name, email],
    );
    await promiseDb.query(
      "UPDATE course_chats SET user_name = ? WHERE user_email = ?",
      [name, email],
    );
    await promiseDb.query(
      "UPDATE feedbacks SET user_name = ? WHERE user_email = ?",
      [name, email],
    );
    await promiseDb.query(
      "UPDATE complaints SET user_name = ? WHERE user_email = ?",
      [name, email],
    );
    await promiseDb.query(
      "UPDATE assignment_submissions SET student_name = ? WHERE student_email = ?",
      [name, email],
    );
    res
      .status(200)
      .json({ message: "Profile and related records updated successfully" });
  } catch (err) {
    console.error("Profile Update Error:", err);
    res.status(500).json({ error: err.message });
  }
});

app.put("/update-password", (req, res) => {
  const { email, oldPassword, newPassword } = req.body;
  const oldEncrypted = hashPassword(oldPassword || "");
  const newEncrypted = hashPassword(newPassword || "");

  db.query(
    "SELECT * FROM users WHERE email = ? AND (password = ? OR password = ?)",
    [email, oldEncrypted, oldPassword],
    (err, data) => {
      if (err) return res.status(500).json({ error: err.message });

      if (data.length > 0) {
        db.query(
          "UPDATE users SET password = ? WHERE email = ?",
          [newEncrypted, email],
          (updateErr) => {
            if (updateErr)
              return res.status(500).json({ error: updateErr.message });
            res.status(200).json({ message: "Password updated successfully" });
          },
        );
      } else {
        res.status(401).json({ error: "Incorrect current password" });
      }
    },
  );
});

app.delete("/delete-account", (req, res) => {
  db.query("DELETE FROM users WHERE email = ?", [req.body.email], (err) =>
    err
      ? res.status(500).json({ error: err.message })
      : res.status(200).json({ message: "Deleted" }),
  );
});

app.get("/users", (req, res) => {
  db.query(
    "SELECT id, name, email, role, avatar, status, first_login, last_login FROM users ORDER BY id DESC",
    (err, data) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json(data),
  );
});

app.put("/update-user-status", (req, res) => {
  db.query(
    "UPDATE users SET status = ? WHERE email = ?",
    [req.body.status, req.body.email.trim()],
    (err) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json({ message: "Status updated" }),
  );
});

app.post(
  "/upload-course",
  (req, res, next) => {
    const uploadMiddleware = upload.fields([
      { name: "thumbnail", maxCount: 1 },
      { name: "video", maxCount: 1 },
    ]);

    uploadMiddleware(req, res, (err) => {
      if (err) {
        console.error("Course upload error:", err.message);
        return res
          .status(500)
          .json({ error: "File upload failed: " + err.message });
      }
      next();
    });
  },
  (req, res) => {
    const {
      title,
      description,
      category,
      difficulty,
      instructorEmail,
      instructorName,
      total_lessons,
    } = req.body;

    const thumbnailUrl =
      req.files && req.files["thumbnail"]
        ? req.files["thumbnail"][0].path
        : null;
    const videoUrl =
      req.files && req.files["video"] ? req.files["video"][0].path : null;

    db.query(
      `INSERT INTO courses (
      title, description, category, difficulty, instructor_email, instructor_name, total_lessons, status, thumbnail_url, video_url
    ) VALUES (?, ?, ?, ?, ?, ?, ?, 'Pending', ?, ?)`,
      [
        title !== undefined ? title : null,
        description !== undefined ? description : null,
        category !== undefined ? category : null,
        difficulty !== undefined ? difficulty : null,
        instructorEmail !== undefined ? instructorEmail : null,
        instructorName !== undefined ? instructorName : null,
        total_lessons ? parseInt(total_lessons) : 4,
        thumbnailUrl !== undefined ? thumbnailUrl : null,
        videoUrl !== undefined ? videoUrl : null,
      ],
      (err) => {
        if (err) {
          console.error("Course insert error:", err.message);
          return res
            .status(500)
            .json({ error: "Database error: " + err.message });
        }
        res.status(200).json({
          message: "Saved successfully with media",
          thumbnail: thumbnailUrl,
          video: videoUrl,
        });
      },
    );
  },
);

app.post(
  "/upload-course-with-media",
  (req, res, next) => {
    const uploadMiddleware = upload.fields([
      { name: "thumbnail", maxCount: 1 },
      { name: "video", maxCount: 1 },
    ]);

    uploadMiddleware(req, res, (err) => {
      if (err) {
        console.error("🔥 Cloudinary/Multer Error:", err.message);
        return res
          .status(500)
          .json({ error: "File upload failed: " + err.message });
      }
      next();
    });
  },
  (req, res) => {
    const {
      title,
      description,
      category,
      difficulty,
      instructorEmail,
      instructorName,
      total_lessons,
    } = req.body;
    const thumbnailUrl =
      req.files && req.files["thumbnail"]
        ? req.files["thumbnail"][0].path
        : null;
    const videoUrl =
      req.files && req.files["video"] ? req.files["video"][0].path : null;

    db.query(
      `INSERT INTO courses (title, description, category, difficulty, instructor_email, instructor_name, total_lessons, status, thumbnail_url, video_url) VALUES (?, ?, ?, ?, ?, ?, ?, 'Pending', ?, ?)`,
      [
        title,
        description,
        category,
        difficulty,
        instructorEmail,
        instructorName,
        total_lessons || 4,
        thumbnailUrl,
        videoUrl,
      ],
      (err) => {
        if (err) return res.status(500).json({ error: err.message });
        res.status(200).json({
          message: "Course published successfully with media!",
          thumbnail: thumbnailUrl,
          video: videoUrl,
        });
      },
    );
  },
);

app.put(
  "/update-course/:id",
  (req, res, next) => {
    const uploadMiddleware = upload.fields([
      { name: "thumbnail", maxCount: 1 },
      { name: "video", maxCount: 1 },
    ]);

    uploadMiddleware(req, res, (err) => {
      if (err)
        return res
          .status(500)
          .json({ error: "File upload failed: " + err.message });
      next();
    });
  },
  (req, res) => {
    const courseId = req.params.id;
    const { title, description, category, difficulty, total_lessons } =
      req.body;

    const thumbnailUrl =
      req.files && req.files["thumbnail"]
        ? req.files["thumbnail"][0].path
        : null;
    const videoUrl =
      req.files && req.files["video"] ? req.files["video"][0].path : null;

    let updateQuery =
      "UPDATE courses SET title = ?, description = ?, category = ?, difficulty = ?, total_lessons = ?";
    let queryParams = [
      title,
      description,
      category,
      difficulty,
      parseInt(total_lessons) || 4,
    ];

    if (thumbnailUrl) {
      updateQuery += ", thumbnail_url = ?";
      queryParams.push(thumbnailUrl);
    }

    if (videoUrl) {
      updateQuery += ", video_url = ?";
      queryParams.push(videoUrl);
    }

    updateQuery += " WHERE id = ?";
    queryParams.push(courseId);

    db.query(updateQuery, queryParams, (err) => {
      if (err)
        return res
          .status(500)
          .json({ error: "Database error: " + err.message });
      res.status(200).json({
        message: "Course updated successfully",
        thumbnail: thumbnailUrl,
        video: videoUrl,
      });
      if (title) {
        db.query(
          "UPDATE enrollments SET course_title = ? WHERE course_id = ?",
          [title, courseId],
        );
        db.query("UPDATE assignments SET course_name = ? WHERE course_id = ?", [
          title,
          courseId,
        ]);
        db.query(
          "UPDATE assignment_submissions SET course_name = ? WHERE course_id = ?",
          [title, courseId],
        );
        db.query("UPDATE feedbacks SET course_name = ? WHERE course_id = ?", [
          title,
          courseId,
        ]);
        db.query("UPDATE complaints SET course_name = ? WHERE course_id = ?", [
          title,
          courseId,
        ]);
        db.query(
          "UPDATE course_chats SET course_name = ? WHERE course_id = ?",
          [title, courseId],
        );
      }
    });
  },
);

app.post(
  "/upload-module-video",
  (req, res, next) => {
    const uploadMiddleware = upload.single("moduleVideo");
    uploadMiddleware(req, res, (err) => {
      if (err)
        return res.status(500).json({ error: "Upload failed: " + err.message });
      next();
    });
  },
  (req, res) => {
    if (!req.file)
      return res.status(400).json({ error: "No video file uploaded." });
    res.status(200).json({ url: req.file.path });
  },
);

app.get("/courses", (req, res) => {
  db.query("SELECT * FROM courses ORDER BY id DESC", (err, data) =>
    err
      ? res.status(500).json({ error: err.message })
      : res.status(200).json(data),
  );
});

app.put("/course-status", (req, res) => {
  db.query(
    "UPDATE courses SET status = ? WHERE id = ?",
    [req.body.status, req.body.id],
    (err) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json({ message: "Success" }),
  );
});

app.get("/enrollments", (req, res) => {
  db.query("SELECT * FROM enrollments ORDER BY id DESC", (err, data) => {
    if (err) return res.status(500).json({ error: err.message });
    res.status(200).json(data);
  });
});

app.post("/enrollments", (req, res) => {
  const {
    course_id,
    course_title,
    student_email,
    student_name,
    instructor_email,
    date,
  } = req.body;
  db.query(
    "INSERT INTO enrollments (course_id, course_title, student_email, student_name, instructor_email, status, `date`) VALUES (?, ?, ?, ?, ?, 'Pending', ?)",
    [
      course_id,
      course_title,
      student_email,
      student_name,
      instructor_email,
      date,
    ],
    (err) => {
      if (err) return res.status(500).json({ error: err.message });
      res.status(200).json({ message: "Enrollment Requested Successfully" });
    },
  );
});

app.put("/enrollments/status", (req, res) => {
  db.query(
    "UPDATE enrollments SET status = ? WHERE id = ?",
    [req.body.status, req.body.id],
    (err) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json({ message: "Status updated" }),
  );
});

app.delete("/enrollments/:id", (req, res) => {
  db.query("DELETE FROM enrollments WHERE id = ?", [req.params.id], (err) =>
    err
      ? res.status(500).json({ error: err.message })
      : res.status(200).json({ message: "Deleted" }),
  );
});

app.get("/course-chats/:courseId", (req, res) => {
  db.query(
    "SELECT * FROM course_chats WHERE course_id = ? ORDER BY id ASC",
    [String(req.params.courseId)],
    (err, data) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json(data),
  );
});

app.post("/course-chats", (req, res) => {
  const {
    course_id,
    course_name,
    user_name,
    user_email,
    message,
    time,
    media_url,
    media_type,
  } = req.body;
  if (!message && !media_url)
    return res.status(400).json({ error: "Missing fields" });
  db.query(
    "INSERT INTO course_chats (course_id, course_name, user_name, user_email, message, `time`, media_url, media_type) VALUES (?, ?, ?, ?, ?, ?, ?, ?)",
    [
      String(course_id),
      String(course_name),
      String(user_name),
      String(user_email),
      String(message || ""),
      String(time),
      media_url || null,
      media_type || null,
    ],
    (err) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json({ message: "Chat saved!" }),
  );
});

app.delete("/course-chats/:id", (req, res) => {
  const { requester_email, requester_role } = req.body;

  db.query(
    "SELECT * FROM course_chats WHERE id = ?",
    [req.params.id],
    (err, data) => {
      if (err) return res.status(500).json({ error: err.message });
      if (data.length === 0)
        return res.status(404).json({ error: "Message not found" });

      const msg = data[0];
      const isOwner = msg.user_email === requester_email;
      const isAdmin = requester_role === "admin";

      if (!isOwner && !isAdmin) {
        return res
          .status(403)
          .json({ error: "Not authorized to delete this message" });
      }

      db.query(
        "DELETE FROM course_chats WHERE id = ?",
        [req.params.id],
        (delErr) =>
          delErr
            ? res.status(500).json({ error: delErr.message })
            : res.status(200).json({ message: "Deleted" }),
      );
    },
  );
});

app.get("/course-chats-latest/:courseId", (req, res) => {
  db.query(
    "SELECT MAX(id) as maxId FROM course_chats WHERE course_id = ?",
    [String(req.params.courseId)],
    (err, data) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json(data[0] || { maxId: 0 }),
  );
});

app.get("/course-feedbacks/:courseId", (req, res) => {
  db.query(
    "SELECT * FROM feedbacks WHERE course_id = ? ORDER BY id DESC",
    [String(req.params.courseId)],
    (err, data) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json(data),
  );
});

app.post("/course-feedbacks", (req, res) => {
  const {
    course_id,
    course_name,
    user_name,
    user_email,
    rating,
    comment,
    date,
  } = req.body;
  db.query(
    "INSERT INTO feedbacks (course_id, course_name, user_name, user_email, rating, comment, `date`) VALUES (?, ?, ?, ?, ?, ?, ?)",
    [
      String(course_id),
      String(course_name || ""),
      String(user_name),
      String(user_email),
      rating,
      String(comment),
      String(date),
    ],
    (err) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json({ message: "Feedback submitted!" }),
  );
});

app.get("/all-complaints", (req, res) => {
  db.query("SELECT * FROM complaints ORDER BY id DESC", (err, data) =>
    err
      ? res.status(500).json({ error: err.message })
      : res.status(200).json(data),
  );
});

app.post("/module-progress", (req, res) => {
  const { course_id, student_email, module_index, completed_at } = req.body;
  db.query(
    `INSERT INTO module_progress (course_id, student_email, module_index, completed_at) 
     VALUES (?, ?, ?, ?) 
     ON DUPLICATE KEY UPDATE completed_at = ?`,
    [
      String(course_id),
      String(student_email),
      module_index,
      completed_at,
      completed_at,
    ],
    (err) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json({ message: "Saved!" }),
  );
});

app.get("/module-progress/:courseId/:studentEmail", (req, res) => {
  db.query(
    "SELECT module_index FROM module_progress WHERE course_id = ? AND student_email = ?",
    [String(req.params.courseId), String(req.params.studentEmail)],
    (err, data) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json(data),
  );
});

app.post("/student-activity", (req, res) => {
  const { student_email, activity_date } = req.body;
  if (!student_email || !activity_date) {
    return res
      .status(400)
      .json({ error: "Missing student_email or activity_date" });
  }
  db.query(
    `INSERT INTO student_activity (student_email, activity_date) 
     VALUES (?, ?) 
     ON DUPLICATE KEY UPDATE activity_date = activity_date`,
    [String(student_email), activity_date],
    (err) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json({ message: "Activity logged" }),
  );
});

app.get("/student-activity/:email", (req, res) => {
  db.query(
    "SELECT DATE_FORMAT(activity_date, '%Y-%m-%d') as activity_date FROM student_activity WHERE student_email = ? ORDER BY activity_date DESC",
    [String(req.params.email)],
    (err, data) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json(data),
  );
});

app.get("/course-complaints/:courseId", (req, res) => {
  db.query(
    "SELECT * FROM complaints WHERE course_id = ? ORDER BY id DESC",
    [String(req.params.courseId)],
    (err, data) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json(data),
  );
});

app.post("/course-complaints", (req, res) => {
  const {
    course_id,
    course_name,
    user_name,
    user_email,
    complaint_text,
    date,
  } = req.body;
  db.query(
    "INSERT INTO complaints (course_id, course_name, user_name, user_email, complaint_text, `date`) VALUES (?, ?, ?, ?, ?, ?)",
    [
      String(course_id),
      String(course_name || ""),
      String(user_name),
      String(user_email),
      String(complaint_text),
      String(date),
    ],
    (err) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json({ message: "Complaint submitted!" }),
  );
});

app.get("/assignments/:courseId", (req, res) => {
  db.query(
    "SELECT * FROM assignments WHERE course_id = ? ORDER BY id DESC",
    [String(req.params.courseId)],
    (err, data) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json(data),
  );
});

app.post("/module-videos", (req, res) => {
  const {
    course_id,
    module_index,
    video_url,
    uploaded_by,
    description,
    duration,
  } = req.body;
  const durationVal =
    duration !== undefined && duration !== null && !isNaN(duration)
      ? Math.round(duration)
      : null;
  db.query(
    `INSERT INTO module_videos (course_id, module_index, video_url, uploaded_by, description, duration) 
     VALUES (?, ?, ?, ?, ?, ?) 
     ON DUPLICATE KEY UPDATE video_url = ?, description = COALESCE(?, description), duration = COALESCE(?, duration)`,
    [
      String(course_id),
      module_index,
      video_url,
      uploaded_by,
      description || null,
      durationVal,
      video_url,
      description || null,
      durationVal,
    ],
    (err) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json({ message: "Saved!" }),
  );
});

app.put("/module-videos/description", (req, res) => {
  const { course_id, module_index, description } = req.body;
  db.query(
    `INSERT INTO module_videos (course_id, module_index, video_url, description) 
     VALUES (?, ?, '', ?) 
     ON DUPLICATE KEY UPDATE description = ?`,
    [String(course_id), module_index, description, description],
    (err) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json({ message: "Description saved!" }),
  );
});

app.get("/module-videos/:courseId", (req, res) => {
  db.query(
    "SELECT * FROM module_videos WHERE course_id = ?",
    [String(req.params.courseId)],
    (err, data) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json(data),
  );
});

app.delete("/module-videos/:courseId/:moduleIndex", (req, res) => {
  db.query(
    "DELETE FROM module_videos WHERE course_id = ? AND module_index = ?",
    [String(req.params.courseId), req.params.moduleIndex],
    (err) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json({ message: "Deleted!" }),
  );
});

app.post("/assignments", (req, res) => {
  const {
    course_id,
    course_name,
    title,
    description,
    due_date,
    instructor_email,
    date,
  } = req.body;
  db.query(
    "INSERT INTO assignments (course_id, course_name, title, description, due_date, instructor_email, `date`) VALUES (?, ?, ?, ?, ?, ?, ?)",
    [
      String(course_id),
      String(course_name || ""),
      String(title),
      String(description),
      String(due_date),
      String(instructor_email),
      String(date),
    ],
    (err) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json({ message: "Assignment created!" }),
  );
});

app.get("/assignment-submissions/:courseId", (req, res) => {
  db.query(
    "SELECT * FROM assignment_submissions WHERE course_id = ? ORDER BY id DESC",
    [String(req.params.courseId)],
    (err, data) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json(data),
  );
});

app.post("/assignment-submissions", (req, res) => {
  const {
    assignment_id,
    course_id,
    student_email,
    student_name,
    submission_text,
    date,
    assignment_title,
    course_name,
  } = req.body;

  db.query(
    "INSERT INTO assignment_submissions (assignment_id, course_id, student_email, student_name, submission_text, `date`, assignment_title, course_name) VALUES (?, ?, ?, ?, ?, ?, ?, ?)",
    [
      assignment_id,
      String(course_id),
      String(student_email),
      String(student_name),
      String(submission_text),
      String(date),
      assignment_title ? String(assignment_title) : null,
      course_name ? String(course_name) : null,
    ],
    (err) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json({ message: "Assignment Submitted!" }),
  );
});

app.put("/assignment-submissions/:id/grade", (req, res) => {
  const { marks, instructor_comment } = req.body;
  db.query(
    "UPDATE assignment_submissions SET marks = ?, instructor_comment = ? WHERE id = ?",
    [marks, instructor_comment, req.params.id],
    (err) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json({ message: "Graded successfully!" }),
  );
});

app.get("/ban-requests", (req, res) => {
  db.query("SELECT * FROM ban_requests ORDER BY id DESC", (err, data) =>
    err
      ? res.status(500).json({ error: err.message })
      : res.status(200).json(data),
  );
});

app.post("/ban-requests", (req, res) => {
  const {
    course_id,
    course_title,
    inst_email,
    inst_name,
    student_email,
    student_name,
    date,
    reason,
  } = req.body;
  db.query(
    "SELECT * FROM ban_requests WHERE course_id = ? AND student_email = ? AND status = 'Pending'",
    [String(course_id), String(student_email)],
    (err, data) => {
      if (err) return res.status(500).json({ error: err.message });
      if (data.length > 0)
        return res.status(400).json({
          error:
            "A pending request already exists for this student in this course.",
        });
      db.query(
        "INSERT INTO ban_requests (course_id, course_title, inst_email, inst_name, student_email, student_name, `date`, reason) VALUES (?, ?, ?, ?, ?, ?, ?, ?)",
        [
          String(course_id),
          String(course_title),
          String(inst_email),
          String(inst_name),
          String(student_email),
          String(student_name),
          String(date),
          reason ? String(reason) : null,
        ],
        (err) =>
          err
            ? res.status(500).json({ error: err.message })
            : res.status(200).json({ message: "Ban request submitted!" }),
      );
    },
  );
});

app.put("/ban-requests/:id", async (req, res) => {
  const { status, studentEmail, instEmail, studentName, courseId } = req.body;
  const promiseDb = db.promise();
  const now = new Date();
  const dateStr = now.toLocaleDateString("en-US", {
    month: "short",
    day: "numeric",
    year: "numeric",
  });
  const timeStr = now.toLocaleTimeString("en-US", {
    hour: "2-digit",
    minute: "2-digit",
  });

  try {
    await promiseDb.query("UPDATE ban_requests SET status = ? WHERE id = ?", [
      status,
      req.params.id,
    ]);
    if (status === "Approved") {
      await promiseDb.query(
        "UPDATE enrollments SET status = 'Banned' WHERE student_email = ? AND course_id = ?",
        [studentEmail, courseId],
      );
      await promiseDb.query(
        "INSERT INTO notifications (identifier, text, color, `date`, `time`, unread) VALUES (?, ?, ?, ?, ?, 1)",
        [
          studentEmail,
          "You have been removed and banned from a specific course by admin approval.",
          "red",
          dateStr,
          timeStr,
        ],
      );
      await promiseDb.query(
        "INSERT INTO notifications (identifier, text, color, `date`, `time`, unread) VALUES (?, ?, ?, ?, ?, 1)",
        [
          instEmail,
          `Your ban request for ${studentName} was approved. They have been removed from your course.`,
          "green",
          dateStr,
          timeStr,
        ],
      );
    } else if (status === "Rejected") {
      await promiseDb.query(
        "INSERT INTO notifications (identifier, text, color, `date`, `time`, unread) VALUES (?, ?, ?, ?, ?, 1)",
        [
          instEmail,
          `Your ban request for ${studentName} has been rejected by the admin.`,
          "red",
          dateStr,
          timeStr,
        ],
      );
    }
    res.status(200).json({ message: `Ban request ${status} successfully!` });
  } catch (err) {
    console.error("Ban Request Processing Error:", err);
    res.status(500).json({ error: err.message });
  }
});

app.get("/notifications/:identifier", (req, res) => {
  db.query(
    "SELECT * FROM notifications WHERE identifier = ? ORDER BY id DESC",
    [req.params.identifier],
    (err, data) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json(data),
  );
});

app.post("/notifications", (req, res) => {
  const { identifier, text, color, date, time } = req.body;
  db.query(
    "INSERT INTO notifications (identifier, text, color, `date`, `time`, unread) VALUES (?, ?, ?, ?, ?, 1)",
    [identifier, text, color, date, time],
    (err) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json({ message: "Added" }),
  );
});

app.put("/notifications/read", (req, res) => {
  db.query(
    "UPDATE notifications SET unread = 0 WHERE identifier = ?",
    [req.body.identifier],
    (err) => {
      if (err) return res.status(500).json({ error: err.message });
      res.status(200).json({ message: "Marked" });
    },
  );
});

app.get("/unread-counts/:userEmail", async (req, res) => {
  const userEmail = req.params.userEmail;
  const promiseDb = db.promise();
  try {
    const [readRows] = await promiseDb.query(
      "SELECT course_id, last_read_message_id FROM chat_read_status WHERE user_email = ?",
      [userEmail],
    );
    const readMap = {};
    readRows.forEach((r) => (readMap[r.course_id] = r.last_read_message_id));

    const [allMessages] = await promiseDb.query(
      `SELECT course_id, MAX(id) as maxId 
       FROM course_chats 
       WHERE user_email != ? 
       GROUP BY course_id`,
      [userEmail],
    );

    let result = [];
    let totalUnread = 0;

    for (let row of allMessages) {
      const lastRead = readMap[row.course_id] || 0;
      const [countRows] = await promiseDb.query(
        "SELECT COUNT(*) as cnt FROM course_chats WHERE course_id = ? AND id > ? AND user_email != ?",
        [row.course_id, lastRead, userEmail],
      );
      const unreadCount = countRows[0].cnt;
      if (unreadCount > 0) {
        result.push({ course_id: row.course_id, unread: unreadCount });
        totalUnread += unreadCount;
      }
    }

    res.status(200).json({ total: totalUnread, rooms: result });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

app.post("/mark-chat-read", (req, res) => {
  const { user_email, course_id, last_message_id } = req.body;
  db.query(
    `INSERT INTO chat_read_status (user_email, course_id, last_read_message_id) 
     VALUES (?, ?, ?) 
     ON DUPLICATE KEY UPDATE last_read_message_id = ?`,
    [user_email, String(course_id), last_message_id || 0, last_message_id || 0],
    (err) =>
      err
        ? res.status(500).json({ error: err.message })
        : res.status(200).json({ message: "Marked as read" }),
  );
});

app.use((req, res) =>
  res.status(404).json({
    error: `API route not found on backend: ${req.method} ${req.url}`,
  }),
);

const PORT = process.env.PORT || 5005;

app.listen(PORT, "0.0.0.0", () => {
  console.log(`🚀 SERVER RUNNING ON PORT ${PORT}`);
});
