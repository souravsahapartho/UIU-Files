import sqlite3

conn = sqlite3.connect("products.db")

cursor = conn.cursor()

conn.execute("""
Create table products(
id text primary key,
name text not null, 
category text not null,
price real not null
)
""")

conn.commit()
conn.close()
print("database created!!!")
