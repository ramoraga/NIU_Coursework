/*
	Reinaldo Moraga
	CSCI 466 Section 2
	Assignment 6
	October 23rd, 2020
*/

USE BabyName;

-- 1. Selects BabyName database 
SELECT * FROM BabyName;

-- 2. Shows all tables in the database
SHOW TABLES;

-- 3. Shows all columns and their types
DESCRIBE BabyName;

-- 4. Shows all of the years, only once, where my first name appears
SELECT DISTINCT year FROM BabyName WHERE name = "Reinaldo";

-- 5. Shows all of the names, only once, from my birth year
SELECT DISTINCT name FROM BabyName WHERE year = 2001;

-- 6. Displays the most popular male and female name from my birth year
SELECT name FROM BabyName WHERE count = (SELECT MAX(count) FROM BabyName WHERE year = 2001 AND gender = "M")
UNION 
SELECT name FROM BabyName WHERE count = (SELECT MAX(count) FROM BabyName WHERE year = 2001 AND gender = "F");

-- 7. Shows all info about the names similar to mine, first in alphabetical order, then by count, and then by year
SELECT * FROM BabyName WHERE name = "Reinaldo";
SELECT * FROM BabyName WHERE name = "Reinaldo" ORDER BY count;
SELECT * FROM BabyName WHERE name = "Reinaldo" ORDER BY year;

-- 8. Shows the number of rows in the table
SELECT COUNT(*) FROM BabyName;

-- 9. Shows the number of names there were in 1972
SELECT COUNT(DISTINCT name) FROM BabyName WHERE year = 1972;

-- 10. Shows the number of names there were for each gender in 1953
SELECT gender, COUNT(DISTINCT name) FROM BabyName WHERE year = 1953 GROUP BY gender;

-- 11. Shows the number of names there are in each place
SELECT place, COUNT(DISTINCT name) FROM BabyName GROUP BY place; 

