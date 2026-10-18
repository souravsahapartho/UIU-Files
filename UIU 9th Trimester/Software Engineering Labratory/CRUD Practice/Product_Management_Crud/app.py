from flask import Flask, render_template, request, redirect
import sqlite3

app = Flask(__name__)


def get_db_conn():
    conn = sqlite3.connect("products.db")
    conn.row_factory = sqlite3.Row
    return conn


@app.route("/")
def index():
    conn = get_db_conn()

    products = conn.execute("Select * from products").fetchall()

    conn.close()

    return render_template("index.html", products=products)


@app.route("/add", methods=("POST", "GET"))
def add():

    if request.method == "POST":
        id = request.form["id"]
        name = request.form["name"]
        category = request.form["category"]
        price = request.form["price"]

        conn = get_db_conn()

        conn.execute(
            "Insert into products(id,name,category, price) Values(?, ?, ?, ?)",
            (id, name, category, price),
        )

        conn.commit()
        conn.close()

        return redirect("/")

    return render_template("add.html")


@app.route("/edit/<id>", methods=("POST", "GET"))
def edit(id):

    conn = get_db_conn()

    product = conn.execute("SELECT * FROM products WHERE id=?", (id,)).fetchone()

    if request.method == "POST":
        name = request.form["name"]
        category = request.form["category"]
        price = request.form["price"]

        conn.execute(
            "UPDATE products SET name=?, category=?, price=? WHERE id=?",
            (name, category, price, id),
        )

        conn.commit()
        conn.close()

        return redirect("/")
    return render_template("edit.html", product=product)


@app.route("/delete/<id>")
def delete(id):
    conn = get_db_conn()

    conn.execute("delete from products where id=?", (id,))

    conn.commit()
    conn.close()

    return redirect("/")


@app.route("/show")
def show():
    conn = get_db_conn()

    products = conn.execute("select * from products where price>30000").fetchall()
    conn.commit()
    conn.close()

    return render_template("show.html", products=products)


@app.route("/increase")
def increase():
    conn = get_db_conn()

    conn.execute("update products set price=price*1.10")

    conn.commit()
    conn.close()

    return redirect("/")


@app.route("/delete1")
def delete1():
    conn = get_db_conn()

    conn.execute(" delete from products where price<3000")

    conn.commit()
    conn.close()

    return redirect("/")


@app.route("/mmh")
def mmh():
    conn = get_db_conn()

    avgprice = conn.execute("select avg(price) as avgprice from products").fetchone()

    maxprice = conn.execute("select max(price) as maxprice from products").fetchone()

    minprice = conn.execute("select min(price) as minprice from products").fetchone()

    conn.commit()
    conn.close()

    return render_template(
        "mmh.html", maxprice=maxprice, minprice=minprice, avgprice=avgprice
    )


@app.route("/search")
def search():
    conn = get_db_conn()

    products = conn.execute("select * from products where Name='Laptop'").fetchall()

    conn.close()
    return render_template("search.html", products=products)


@app.route("/asc")
def asc():
    conn = get_db_conn()

    products = conn.execute("select * from products order by price ASC").fetchall()

    conn.close()

    return render_template("asc.html", products=products)


@app.route("/desc")
def desc():
    conn = get_db_conn()

    products = conn.execute("select * from products order by price desc").fetchall()

    conn.close()

    return render_template("desc.html", products=products)


@app.route("/count")
def count():
    conn = get_db_conn()

    count = conn.execute("select count(*) as count from products").fetchone()

    conn.commit()
    conn.close()

    return render_template("count.html", count=count)


if __name__ == "__main__":
    app.run(debug=True)
