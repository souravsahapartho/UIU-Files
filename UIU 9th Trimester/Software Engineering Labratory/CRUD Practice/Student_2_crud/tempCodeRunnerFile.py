from flask import Flask, render_template, redirect

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