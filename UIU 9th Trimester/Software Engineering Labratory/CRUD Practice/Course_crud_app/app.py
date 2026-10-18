from flask import Flask, render_template, request, redirect
import sqlite3

app = Flask(__name__)


def get_db_conn():
    conn = sqlite3.connect("course.db")
    conn.row_factory = sqlite3.Row
    return conn


@app.route("/")
def index():
    conn = get_db_conn()

    courses = conn.execute("SELECT * FROM courses").fetchall()

    conn.close()
    return render_template("index.html", courses=courses)


@app.route("/add", methods=("POST", "GET"))
def add():
    if request.method == "POST":
        id = request.form["id"]
        title = request.form["title"]
        fee = request.form["fee"]

        conn = get_db_conn()

        conn.execute(
            "Insert into courses(id, title,fee) Values(?,?,?)",
            (id, title, fee),
        )

        conn.commit()
        conn.close()

        return redirect("/")

    return render_template("add.html")


@app.route("/high")
def high():
    conn = get_db_conn()

    courses = conn.execute("Select * from courses where fee > 5000").fetchall()

    conn.close()

    return render_template("high.html", courses=courses)


@app.route("/update")
def update():
    conn = get_db_conn()

    conn.execute("Update courses Set fee=fee*1.10")
    conn.commit()

    courses = conn.execute("Select * from courses").fetchall()

    conn.close()

    return render_template("update.html", courses=courses)


@app.route("/delete")
def delete():
    conn = get_db_conn()
    conn.execute("Delete from courses where fee<6000")

    conn.commit()
    courses = conn.execute("Select * from courses").fetchall()

    conn.close()
    return render_template("delete.html", courses=courses)


@app.route("/avg")
def avg():
    conn = get_db_conn()

    avgfee = conn.execute("SELECT AVG(fee) AS avgfee FROM courses").fetchone()

    conn.close()

    return render_template("avg.html", avgfee=avgfee)


@app.route("/max_min")
def max_min():
    conn = get_db_conn()

    maxfee = conn.execute("SELECT MAX(fee) AS maxfee FROM courses").fetchone()

    minfee = conn.execute("SELECT MIN(fee) AS minfee FROM courses").fetchone()

    conn.close()

    return render_template("max_min.html", maxfee=maxfee, minfee=minfee)


if __name__ == "__main__":
    app.run(debug=True)
