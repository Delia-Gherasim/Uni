use Concerts
drop table SaveVersion
drop table participantConcert
drop table EventStaff
drop table Staff
drop table Participants
drop table Event
drop table Locations
drop table Effects
drop table Concert
drop table Dj
drop table Songs
drop table Bands

go

create table SaveVersion(
	number int ,
	performedProcedure varchar(30),
	reversalProcedure varchar(30)
);
insert into SaveVersion values(0, 'original', '');

CREATE TABLE Bands(
	bandId int IDENTITY(1,1),
	bandName varchar(30),
	vocalist varchar(30),
	guitarist varchar(30),
	basist varchar(30),
	manager varchar(30),
	PRIMARY KEY(bandId));

CREATE TABLE Songs(
	songId int NOT NULL IDENTITY(1,1),
	name varchar(30) NOT NULL,
	bandId int NOT NULL,
	album varchar(30),
	minutes int NOT NULL,
	PRIMARY KEY(songId),
	FOREIGN KEY(bandId) REFERENCES Bands(bandId));

CREATE TABLE Dj(
	djId int IDENTITY(1,1),
	name varchar(30) NOT NULL,
	stageName varchar(30) NOT NULL,
	PRIMARY KEY(djId));

CREATE TABLE Concert(
	concertId int IDENTITY(1,1),
	bandId int,
	djId int,
	FOREIGN KEY(djId) REFERENCES Dj(djId),
	fans int,
	date date,
	startTime time,
	endTime time,
	PRIMARY KEY(concertId),
	FOREIGN KEY(bandId) REFERENCES Bands(bandId) );
	--ON DELETE SET NULL);

CREATE TABLE Effects(
	concertId int NOT NULL,
	fireworks bit,
	lasers bit,
	projectorScreen bit,
	FOREIGN KEY(concertId) REFERENCES Concert(concertID));

CREATE TABLE Locations(
	locationId int NOT NULL IDENTITY(1, 1),
	name varchar(30) NOT NULL,
	addres varchar(50) NOT NULL,
	streetNumber int, 
	city varchar(50) NOT NULL,
	PRIMARY KEY(locationId));

CREATE TABLE Event(
	eventId int NOT NULL IDENTITY(1,1),
	eventName varchar(30) NOT NULL,
	concertId int,
	locationId int NOT NULL,
	organizer varchar(30),
	staff int,
	PRIMARY KEY(eventId),
	FOREIGN KEY(concertId) REFERENCES Concert(concertId),
	FOREIGN KEY(locationId) REFERENCES Locations(locationId));

CREATE TABLE Participants(
	participantCNP int NOT NULL,
	name varchar(30) NOT NULL,
	surname varchar(30) NOT NULL,
	dateOfBirth date NOT NULL,
	PRIMARY KEY(participantCNP));

CREATE TABLE Staff(
	staffCNP int NOT NULL,
	name varchar(30) NOT NULL,
	surname varchar(30) NOT NULL,
	department varchar(30) NOT NULL,
	hoursWorked int,
	salary int,
	PRIMARY KEY(staffCNP));

CREATE TABLE EventStaff(
	id int NOT NULL IDENTITY(1,1),
	eventId int NOT NULL, 
	staffCNP int NOT NULL,
	PRIMARY KEY(id),
	FOREIGN KEY(eventId) REFERENCES Event(eventId),
	FOREIGN KEY(staffCNP) REFERENCES Staff(staffCNP));

CREATE TABLE participantConcert(
	id int NOT NULL IDENTITY(1,1),
	participantCNP int NOT NULL,
	concertID int NOT NULL,
	PRIMARY KEY(id),
	FOREIGN KEY(participantCNP) REFERENCES Participants(participantCNP),
	FOREIGN KEY(concertId) REFERENCES Concert(concertId));



