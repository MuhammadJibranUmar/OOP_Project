CREATE DATABASE university;
USE university;
CREATE TABLE student(
  rollNo int, 
  registrationNo int NOT NULL UNIQUE,
  firstName varchar(30),
  lastName varchar(30),
  address text,
  email varchar(30),
  phone varchar(12)
);
