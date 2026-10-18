import sqlite3

conn = sqlite3.connect("students2.db")

cursor = conn.cursor()

cursor.execute("""
CREATE Table students(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    email TEXT NOT NULL,
    department TEXT NOT NULL
                )
""")

conn.commit()
conn.close()

print("Database successfully created!!!")
