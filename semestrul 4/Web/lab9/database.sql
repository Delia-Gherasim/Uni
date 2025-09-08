create database webLab9;
use webLab9;
drop table Posts;
drop table Users;

CREATE TABLE Users (
    userId INT AUTO_INCREMENT PRIMARY KEY,
    password VARCHAR(30) NOT NULL,
    userName VARCHAR(50) NOT NULL,
    email VARCHAR(50) NOT NULL
);

CREATE TABLE Posts (
    postId INT AUTO_INCREMENT PRIMARY KEY,
	photo VARCHAR(50),
    votes INT NOT NULL,
    userId INT NOT NULL,
    FOREIGN KEY (userId) REFERENCES Users(userId) ON DELETE CASCADE
);

insert into Users(password, userName, email) values
( "pass1", "user1", "email1"),
( "pass2", "user2", "email2"),
( "pass3", "user3", "email3"),
( "pass4", "user4", "email4") ;

insert into Posts(photo, votes, userId) values
( "C:\Facultation\sem4\web\lab9\photos\1.jpeg", 3, 1),
( "C:\Facultation\sem4\web\lab9\photos\2.jpeg", 2, 1),
( "C:\Facultation\sem4\web\lab9\photos\3.jpeg", 4, 2),
( "C:\Facultation\sem4\web\lab9\photos\4.jpeg", 4, 3),
( "C:\Facultation\sem4\web\lab9\photos\5.jpeg", 1, 3);

select * from Posts;