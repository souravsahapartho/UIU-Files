const express = require("express");
const mysql = require("mysql2");
const bodyParser = require("body-parser");
const app = express();

app.set("view engine", "ejs");
app.use(bodyParser.urlencoded({ extended: true }));

// MySQL Connection
const db = mysql.createConnection({
  host: "localhost",
  user: "root",
  password: "", // Your MySQL password here
  database: "todo_db",
});

// 1. Display Tasks (GET)
app.get("/", (req, res) => {
  db.query("SELECT * FROM tasks", (err, results) => {
    if (err) throw err;
    // Sending the database results to your HTML template
    res.render("index", { tasks: results });
  });
});

// 2. Add Task (POST)
app.post("/add", (req, res) => {
  const { name, due } = req.body;
  db.query(
    "INSERT INTO tasks (task_name, due_time) VALUES (?, ?)",
    [name, due],
    () => {
      res.redirect("/");
    },
  );
});

// 3. Remove Task (POST)
app.post("/remove", (req, res) => {
  const id = req.body.id;
  db.query("DELETE FROM tasks WHERE id = ?", [id], () => {
    res.redirect("/");
  });
});

app.listen(3000, () => console.log("Server running on http://localhost:3000"));
