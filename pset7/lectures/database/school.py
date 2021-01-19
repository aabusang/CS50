import csv
from cs50 import SQL

open ("students.db", "w").close()

db = SQL("sqlite:///students.db")
db.execute("CREATE TABLE student(id INTEGER, name TEXT, PRIMARY KEY(id)")
db.execute("CREATE TABLE schools(school_id INTEGER, school TEXT, FOREIGN KEY(school_id) REFERENCES student(id)")

name = input("School Name: ").strip().upper()

with open ("G-Accra-Schools - Sheet1.csv","r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        name = row["School"].strip().upper()

        db.execute("INSERT INTO students (name), VALUES(?)", name)
