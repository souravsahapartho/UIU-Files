import sqlite3

conn = sqlite3.connect("course.db")

cursor = conn.cursor()

cursor.execute("""
create table courses(
id text Primary key,
title text not null,
fee int not null
)
""")

conn.commit()
conn.close()

print("database succesfully created!!!")
