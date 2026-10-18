from flask import Flask, render_template, redirect, request

import sqlite3

app = Flask(__name__)


def get_db_conn():
    conn = sqlite3.connect("students3.db")
    conn.row_factory = sqlite3.Row
    return conn


@app.route("/")
def index():
    conn = get_db_conn()

    students = conn.execute("select * from students").fetchall()

    conn.close()
    return render_template("index.html", students=students)


@app.route("/add", methods=("POST", "GET"))
def add():
    if request.method == "POST":
        id = request.form["id"]
        name = request.form["name"]
        department = request.form["department"]
        cgpa = request.form["cgpa"]

        conn = get_db_conn()

        conn.execute(
            "INSERT INTO students (id, name, department, cgpa) VALUES (?, ?, ?, ?)",
            (id, name, department, cgpa),
        )
        conn.commit()
        conn.close()

        return redirect("/")

    return render_template("add.html")


if __name__ == "__main__":
    app.run(debug=True)
