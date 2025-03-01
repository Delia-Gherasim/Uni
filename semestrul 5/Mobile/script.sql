drop database if exists mobile;
CREATE DATABASE mobile;

USE mobile;

DROP TABLE IF EXISTS Movie;

-- Create the Movie table
CREATE TABLE Movie (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(30) NOT NULL,
    genre VARCHAR(50) NOT NULL,
    status BOOL,
    director VARCHAR(50) NOT NULL,
    description VARCHAR(300) NOT NULL,
    rating FLOAT
);

-- Insert movie records
INSERT INTO Movie (name, genre, status, director, description, rating) VALUES
('Barbie', 'Adventure', true, 'Greta Gerwig', 'Barbie embarks on a journey of self-discovery and empowerment while navigating the challenges of both the real and fantastical worlds.', 4.2),
('Smile2', 'Horror', true, 'John Doe', 'The sequel to Wicked Smile, continuing the tale of the demonic entity that haunts the small town. New terror awaits as the dark forces grow stronger.', 3.8),
('Pirates of the Caribbean', 'Fantasy', true, 'Gore Verbinski', 'Captain Jack Sparrow teams up with Will Turner to battle cursed pirates and retrieve the cursed treasure from the Black Pearl.', 4.7),
('Beetlejuice', 'Fantasy', true, 'Tim Burton', 'A recently deceased couple hires the eccentric bio-exorcist Beetlejuice to scare away the new living inhabitants of their home.', 4.4);

SELECT * FROM Movie;
