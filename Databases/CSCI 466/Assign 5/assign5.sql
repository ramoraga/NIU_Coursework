/*
	Reinaldo Moraga
	CSCI 466 Section 2
	Assignment 5
	October 7th, 2020
*/


-- 1. Drop existing tables
DROP TABLE IF EXISTS Visits, Dogs;

-- 2. Create Dogs table
CREATE TABLE Dogs(
  ID		INT AUTO_INCREMENT,
  BREED		VARCHAR(20)	NOT NULL,
  NAME		VARCHAR(10)	NOT NULL,
  
  PRIMARY KEY (ID)
);

-- 3. Insert example data in Dogs table
INSERT INTO Dogs
	(BREED, NAME)
    VALUES ('Corgi',
            'Cookie'),
           ('Beagle',
            'Peanut'),
           ('Huskie',
            'Victor'),
           ('Chow Chow',
            'Simba'),
           ('Shiba Inu',
            'Ollie');

-- 4. Show Schema for Dogs table
DESCRIBE Dogs;

-- 5. Display the data table for Dogs
SELECT * FROM Dogs;

-- 6. Create Visits table
CREATE TABLE Visits(
  VISIT_ID	INT AUTO_INCREMENT,
  DOG_ID	INT NOT NULL,
  VISIT_DATE	DATE NOT NULL,
  
  PRIMARY KEY (VISIT_ID),
  FOREIGN KEY (DOG_ID) REFERENCES Dogs(ID)
);

-- 7. Insert example data in Visits table
INSERT INTO Visits
	(DOG_ID, VISIT_DATE)
    VALUES ((SELECT ID FROM Dogs WHERE NAME = 'Ollie'),
           	DATE '2001-01-25'),
           ((SELECT ID FROM Dogs WHERE NAME = 'Victor'),
           	DATE '2019-08-26'),
           ((SELECT ID FROM Dogs WHERE NAME = 'Cookie'),
           	DATE '2019-08-27'),
           ((SELECT ID FROM Dogs WHERE NAME = 'Ollie'),
           	DATE '2019-09-18'),
           ((SELECT ID FROM Dogs WHERE NAME = 'Simba'),
           	DATE '2019-10-31'),
           ((SELECT ID FROM Dogs WHERE NAME = 'Peanut'),
           	DATE '2019-12-31'),
           ((SELECT ID FROM Dogs WHERE NAME = 'Simba'),
           	DATE '2020-01-01'),
           ((SELECT ID FROM Dogs WHERE NAME = 'Ollie'),
           	CURRENT_DATE);
     
-- 8. Show Schema for Visits table  
DESCRIBE Visits;

-- 9. Display data table for Visits
SELECT * FROM Visits;

-- 10. Add new column in Visits table
ALTER TABLE Visits ADD VISIT_TIME TIME;

-- 11. Add example data for new column in Visits table
UPDATE Visits
	SET VISIT_TIME = CURTIME()
    WHERE YEAR(VISIT_DATE) = '2019';
    
-- 12. Display updated data table for Visits
SELECT * FROM Visits;    
