-- create database practic
use practic
go

drop table if exists CityBrokerages;
drop table if exists Brokerage;
drop table if exists Cities;
drop table if exists FinancialProducts;
drop table if exists Clients;
go

create table Clients(
	clientId int primary key identity(1,1),
	name varchar(30),
	dateOfBirth date,
	dateOfRegistration date,
	country varchar(30));

create table Cities(
	cityId int primary key identity(1,1),
	name varchar(30),
	country varchar(30));

create table FinancialProducts(
	productId int primary key identity(1,1),
	name varchar(30),
	price int);

create table Brokerage(
	brokId int primary key identity(1,1),
	name varchar(30),
	nrOfEmployees int,
	clientId int,
	foreign key(clientId) references Clients(clientId),
	productId int,
	foreign key(productId) references FinancialProducts(productId));

create table CityBrokerages(
	cityId int,
	foreign key(cityId) references Cities(cityId),
	brokId int,
	foreign key(brokId) references Brokerage(brokId));

select * from Brokerage
select * from Clients
insert into Clients (name, dateOfBirth, dateOfRegistration, country)
values
('Maria', '1980-02-03', '2020-01-15', 'USA'),
('John', '1975-08-23', '2019-11-22', 'Canada'),
('Ana', '1990-05-30', '2021-03-01', 'UK'),
('Gigi', '1985-12-17', '2022-07-12', 'Australia'),
('Mirces', '1992-10-05', '2023-02-18', 'Romania');
insert into FinancialProducts (name, price)
values
('A', 100),
('B', 200),
('C', 300),
('D', 400),
('E', 500);
insert into Brokerage (name, nrOfEmployees, clientId, productId)
values
('unu', 50, 1, 1),
('doi', 30, 2, 2),
('trei', 20, 3, 3),
('4', 40, 4, 4),
('5', 60, 5, 5);


