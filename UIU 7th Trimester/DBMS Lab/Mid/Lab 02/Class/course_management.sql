CREATE DATABASE university;

CREATE TABLE course ( 
course_code VARCHAR(20) PRIMARY KEY, course_name VARCHAR(20) NOT NULL,
credit INT
);

CREATE TABLE student (
id int PRIMARY KEY,
name varchar (30),
age int,
course_taken varchar(20) REFERENCES course(course_code)
);

INSERT INTO course VALUES ('CSE 101', 'SPL', 3), ('CSE 102', 'SPL Lab', 1), ('CSE 103', 'OOP', 3), ('CSE 104', 'OOP Lab', 1);
 
INSERT INTO student VALUES (1, 'ABC', 19, 'CSE 101'), (2, 'XYZ', 24, 'CSE 104');

ALTER TABLE student ADD column Email VARCHAR(20);

ALTER TABLE student ADD COLUMN (
CGPA FLOAT(3,2),
Hobby Varchar(20)
);

ALTER TABLE course MODIFY COLUMN credit FLOAT(2,1);

ALTER TABLE student DROP COLUMN Hobby;

ALTER TABLE student CHANGE name fullname VARCHAR(20);

ALTER TABLE course RENAME university_courses;

DROP TABLE student;
