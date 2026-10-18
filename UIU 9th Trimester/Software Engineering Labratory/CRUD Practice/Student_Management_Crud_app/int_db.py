import sqlite3

conn=sqlite3.connect("students.db")

cursor=conn.cursor()

conn.execute("""
CREATE table students(
id text primary key, 
name text not null,
department text not null,
cgpa real not null,
semester text not null)
""")

conn.commit()
conn.close()
print("Database created succesfully!!!!")