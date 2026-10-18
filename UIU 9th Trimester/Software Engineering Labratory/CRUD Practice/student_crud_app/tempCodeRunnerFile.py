from flask import Flask, render_template, request, redirect
import sqlite3

app = Flask(__name__)


def get_db_conn():
    conn = sqlite3.connect("students2.db")
    conn.row_factory = sqlite3.Row
    return conn


@app.route("/")
def index():
    conn = get_db_conn()

    students = conn.execute("Select * From students").fetchall()

    conn.close()

    return render_template("index.html", students=students)


@app.route("/add", methods=("POST", "GET"))
def add():
    if request.method == "POST":
        name = request.form["name"]
        email = request.form["email"]
        department = request.form["department"]

        conn = get_db_conn()

        conn.execute(
            "Insert into students (name, email, department) VALUES (?, ?, ?)",
            (name, email, department),
        )

        conn.commit()
        conn.close()

        return redirect("/")
    return render_template("add.html")


@app.route("/edit/<int:id>", methods=("GET", "POST"))
def edit(id):
    conn = get_db_conn()

    student = conn.execute("Select * from students where id =?", (id,)).fetchone()

    if request.method == "POST":
        name = request.form["name"]
        email = request.form["email"]
        department = request.form["department"]

        conn.execute(
            "update students set name=?, email=?, department=? where id=?",
            (name, email, department, id),
        )

        conn.commit()
        conn.close()

        return redirect("/")

    return render_template("edit.html", student=student)


@app.route("/delete/<int:id>")
def delete(id):
    conn = get_db_conn()

    conn.execute("Delete from students where id=?", (id,))

    conn.commit()
    conn.close()

    return redirect("/")


if __name__ == "__main__":
    app.run(debug=True)
