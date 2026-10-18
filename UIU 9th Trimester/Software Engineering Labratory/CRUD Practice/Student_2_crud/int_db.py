import sqlite3

conn = sqlite3.connect("students3.db")

cursor = conn.cursor()

conn.execute("""
create table students(
id text primary key,
name text not null,
department text not null,
cgpa real not null
)
""")

conn.commit()
conn.close()
print("database created!!!")
