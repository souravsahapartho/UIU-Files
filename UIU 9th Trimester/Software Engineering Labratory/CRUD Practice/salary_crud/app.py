from flask import Flask, render_template, request, redirect

import sqlite3

app = Flask(__name__)


def get_db_conn():
    conn = sqlite3.connect("salary.db")
    conn.row_factory = sqlite3.Row
    return conn


@app.route("/")
def index():
    conn = get_db_conn()

    salarys = conn.execute("Select * from salarys").fetchall()

    conn.close()

    return render_template("index.html", salarys=salarys)


@app.route("/add", methods=("POST", "GET"))
def add():
    if request.method == "POST":
        id = request.form["id"]
        name = request.form["name"]
        department = request.form["department"]
        salary = request.form["salary"]

        conn = get_db_conn()

        conn.execute(
            "Insert into salarys(id, name, department, salary) VALUES(?,?,?,?)",
            (id, name, department, salary),
        )

        conn.commit()
        conn.close()

        return redirect("/")

    return render_template("/add.html")


@app.route("/edit/<id>", methods=("POST", "GET"))
def edit(id):
    conn = get_db_conn()

    salary = conn.execute("Select * from salarys where id=?", (id,)).fetchone()

    if request.method == "POST":
        name = request.form["name"]
        department = request.form["department"]
        salary = request.form["salary"]

        conn.execute(
            "update salarys set name=?, department=?, salary=? where id=?",
            (name, department, salary, id),
        )

        conn.commit()
        conn.close()

        return redirect("/")

    return render_template("edit.html", salary=salary)


@app.route("/delete/<id>")
def delete(id):
    conn = get_db_conn()

    conn.execute("delete from salarys where id=?", (id,))

    conn.commit()
    conn.close()

    return redirect("/")


@app.route("/show")
def show():
    conn = get_db_conn()

    salarys = conn.execute("select * from salarys where salary>40000").fetchall()

    conn.commit()
    conn.close()

    return render_template("show.html", salarys=salarys)


@app.route("/increase")
def increase():
    conn = get_db_conn()

    conn.execute("update salarys set salary=salary*1.10")

    conn.commit()
    conn.close()

    return redirect("/")


@app.route("/delete3")
def delete3():
    conn = get_db_conn()

    conn.execute("delete from salarys where salary<30000")

    conn.commit()
    conn.close()

    return redirect("/")


@app.route("/max_min_avg")
def max_min_avg():
    conn = get_db_conn()

    avgsal = conn.execute("select avg(salary) as avgsal from salarys").fetchone()

    maxsal = conn.execute("select max(salary) as maxsal from salarys").fetchone()

    minsal = conn.execute("select min(salary) as minsal from salarys").fetchone()

    conn.commit()
    conn.close()

    return render_template("mmh.html", maxsal=maxsal, minsal=minsal, avgsal=avgsal)


@app.route("/alice")
def alice():
    conn = get_db_conn()

    salarys = conn.execute("select * from salarys where name='Alice'").fetchall()

    conn.close()
    return render_template("alice.html", salarys=salarys)


@app.route("/sort")
def sort():
    conn = get_db_conn()
    salarys = conn.execute("select * from salarys order by salary ASC").fetchall()

    conn.commit()
    conn.close()

    return render_template("sort.html", salarys=salarys)


@app.route("/desc")
def desc():
    conn = get_db_conn()

    salarys = conn.execute("select * from salarys order by salary DESC").fetchall()

    conn.commit()
    conn.close()

    return render_template("desc.html", salarys=salarys)


@app.route("/count")
def count():
    conn = get_db_conn()

    count = conn.execute("select count(*) as count from salarys").fetchone()

    conn.commit()
    conn.close()

    return render_template("count.html", count=count)


if __name__ == "__main__":
    app.run(debug=True)
