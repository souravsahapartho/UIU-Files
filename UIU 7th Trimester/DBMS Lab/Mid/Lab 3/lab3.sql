DROP DATABASE IF EXISTS fall25_lab3;
CREATE DATABASE IF NOT EXISTS fall25_lab3;
USE fall25_lab3;

-- Create tables

CREATE TABLE department (
  dname          VARCHAR(15),
  dnumber        INT NOT NULL,
  mgrssn         INT,
  mgrstartdate   DATE,
  PRIMARY KEY (dnumber)
);



CREATE TABLE employee (
  fname           VARCHAR(15),
  minit           VARCHAR(2),
  lname           VARCHAR(15),
  ssn             INT(12) NOT NULL,
  bdate           DATE,
  address         VARCHAR(35),
  gender          VARCHAR(1),
  salary          INT(7) NOT NULL,
  superssn        INT(12),
  dno             INT NOT NULL,
  PRIMARY KEY (ssn),
  CONSTRAINT fk_dno_dnumber FOREIGN KEY (dno) REFERENCES department (dnumber)
);


CREATE TABLE dependent (
  essn                   INT,
  dependent_name         VARCHAR(15),
  gender                 VARCHAR(1),
  bdate                  DATE,
  relationship           VARCHAR(12),
  PRIMARY KEY (essn, dependent_name),
  CONSTRAINT fk_essn_ssn FOREIGN KEY (essn) REFERENCES employee (ssn)
);

-- Insert Data

INSERT INTO department VALUES ('RESEARCH', 5, 333445555, '1978-05-22');
INSERT INTO department VALUES ('ADMINISTRATION', 4, 987654321, '1985-01-01');
INSERT INTO department VALUES ('HEADQUARTERS', 1, 888665555, '1971-06-19');

-- Insert values into employee table
INSERT INTO employee VALUES
('JOHN','B','SMITH',123456789,'1955-01-09','731 FONDREN, HOUSTON, TX', 'M',30000,333445555,5);
INSERT INTO employee VALUES
('FRANKLIN','T','WONG',333445555,'1945-12-08','638 VOSS, HOUSTON, TX', 'M',40000,888665555,5);
INSERT INTO employee VALUES
('ALICIA','J','ZELAYA',999887777,'1958-07-19','3321 CASTLE, SPRING, TX', 'F',25000,987654321,4);
INSERT INTO employee VALUES
('JENNIFER','S','WALLACE',987654321,'1931-06-20','291 BERRY, BELLAIRE, TX', 'F',43000,888665555,4);
INSERT INTO employee VALUES
('RAMESH','K','NARAYAN',666884444,'1952-09-15','975 FIRE OAK, HUMBLE, TX', 'M',38000,333445555,5);
INSERT INTO employee VALUES
('JOYCE','A','ENGLISH',453453453,'1962-07-31','5631 RICE, HOUSTON, TX', 'F',25000,333445555,5);

INSERT INTO employee VALUES
('AHMAD','V','JABBAR',987987987,'1959-03-29','980 DALLAS, HOUSTON, TX', 'M',25000,987654321,4);
INSERT INTO employee VALUES 
('JAMES','E','BORG',888665555,'1927-11-10', '450 STONE, HOUSTON, TX', 'M',55000,NULL,1);

-- Insert values into dependent table
INSERT INTO dependent VALUES (333445555,'ALICE','F','1976-04-05','DAUGHTER');
INSERT INTO dependent VALUES (333445555,'THEODORE','M','1973-10-25','SON');
INSERT INTO dependent VALUES (333445555,'JOY','F','1948-05-03','SPOUSE');
INSERT INTO dependent VALUES (123456789,'MICHAEL','M','1978-01-01','SON');
INSERT INTO dependent VALUES (123456789,'ALICE','F','1978-12-31','DAUGHTER');
INSERT INTO dependent VALUES (123456789,'ELIZABETH','F','1957-05-05','SPOUSE');
INSERT INTO dependent VALUES (987654321,'ABNER','M','1932-02-26','SPOUSE');

