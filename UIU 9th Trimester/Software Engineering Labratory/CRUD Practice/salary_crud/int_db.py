import sqlite3

conn = sqlite3.connect("salary.db")

cursor = conn.cursor()

conn.execute("""
create table salarys(
id text primary key,
name text not null, 
department text not null,
salary int not null)
""")

conn.commit()
conn.close()

print("Database created!!!")
