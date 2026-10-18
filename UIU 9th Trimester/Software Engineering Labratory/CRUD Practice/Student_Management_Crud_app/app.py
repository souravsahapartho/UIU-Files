from flask import Flask, render_template, request, redirect
import sqlite3

app = Flask(__name__)


def get_db_conn():
    conn = sqlite3.connect("students.db")
    conn.row_factory = sqlite3.Row
    return conn


@app.route("/")
def index():
    conn = get_db_conn()

    students = conn.execute("Select * from students").fetchall()

    conn.close()
    return render_template("index.html", students=students)


@app.route("/add", methods=("POST", "GET"))
def add():

    if request.method == "POST":
        id = request.form["id"]
        name = request.form["name"]
        department = request.form["department"]
        cgpa = request.form["cgpa"]
        semester = request.form["semester"]

        conn = get_db_conn()

        conn.execute(
            "Insert into students(id, name, department, cgpa, semester) Values(?,?,?,?,?)",
            (id, name, department, cgpa, semester),
        )

        conn.commit()
        conn.close()

        return redirect("/")

    return render_template("add.html")


@app.route("/high")
def high():
    conn = get_db_conn()

    students = conn.execute("Select * from students where cgpa>3.50").fetchall()

    conn.close()

    return render_template("high.html", students=students)


@app.route("/update")
def update():
    conn = get_db_conn()
    conn.execute(
        "Update students set cgpa= case when cgpa+0.10>4.00 then 4.00 else cgpa+0.10 end"
    )

    conn.commit()

    students = conn.execute("Select * from students").fetchall()
    conn.close()
    return render_template("update.html", students=students)


@app.route("/delete")
def delete():
    conn = get_db_conn()
    conn.execute("Delete from students where cgpa<3.00")

    conn.commit()
    conn.execute("select * from students").fetchall()
    conn.close()
    return redirect("/")


@app.route("/avg")
def avg():
    conn = get_db_conn()
    avgcgpa = conn.execute("select avg(cgpa) as avgcgpa from students").fetchone()
    conn.close()
    return render_template("avg.html", avgcgpa=avgcgpa)


@app.route("/max_min")
def max_min():
    conn = get_db_conn()
    maxfee = conn.execute("select max(cgpa) as maxfee from students").fetchone()

    minfee = conn.execute("select min(cgpa) as minfee from students").fetchone()

    conn.close()

    return render_template("max_min.html", maxfee=maxfee, minfee=minfee)


@app.route("/count")
def count():
    conn = get_db_conn()
    count = conn.execute(
        "select count(*) as count from students where department='CSE'"
    ).fetchone()

    conn.close()

    return render_template("count.html", count=count)


@app.route("/sort")
def sort():
    conn = get_db_conn()

    students = conn.execute("select * from students order by cgpa desc").fetchall()

    conn.commit()
    conn.close()
    return render_template("sort.html", students=students)


@app.route("/search/<id>")
def search(id):
    conn = get_db_conn()

    student = conn.execute("select * from students where id=?", (id,)).fetchone()

    conn.close()

    return render_template("search.html", student=student)


if __name__ == "__main__":
    app.run(debug=True)
