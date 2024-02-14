/*Create a database to manage train schedules. The database will store data about the routes of all the trains. The
entities of interest to the problem domain are: Trains, Train Types, Stations, and Routes. Each train has a name and
belongs to a type. A train type has a name and a description. Each station has a name. Station names are unique.
Each route has a name, an associated train, and a list of stations with arrival and departure times in each station.
Route names are unique. The arrival and departure times are represented as hour:minute pairs, e.g., train arrives
at 5 pm and leaves at 5:10 pm.*/
/*1. Write an SQL script that creates the corresponding relational data model.*/
use pregateisan
if exists (select * from information_schema.tables where table_name = 'RutaStations')
	drop table RutaStations
if exists (select * from information_schema.tables where table_name = 'Ruta')
	drop table Ruta
if exists (select * from information_schema.tables where table_name = 'Station')
	drop table Station
if exists (select * from information_schema.tables where table_name = 'Trains')
	drop table Trains
if exists (select * from information_schema.tables where table_name = 'TrainTypes')
	drop table TrainTypes
go
go

create table TrainTypes(
	typeId int identity(1,1),
	name varchar(30) unique,
	descr varchar(50),
	primary key(typeId ));

create table Trains(
	trainId int identity(1,1),
	name varchar(30),
	trainType int
	primary key(trainId),
	foreign key(trainType) references TrainTypes(typeId));

create table Station(
	stationId int identity(1,1),
	name varchar(30),
	primary key(stationId));

create table Ruta(
	name varchar(30) unique,
	trainId int,
	foreign key(trainId) references Trains(trainId));

create table RutaStations(
	ruta varchar(30),
	stationId int,
	arrival time,
	departure time,
	foreign key(ruta) references Ruta(name),
	foreign key (stationId) references Station(stationId));

insert into TrainTypes(name, descr) values
('t1', 'd1'),
('t2', 'd2'),
('t3', 'd3');
insert into Trains(name, trainType) values
('thomas', 1),
('george', 2),
('captain', 3);
insert into Station(name) values
('Cluj'),
('Sv'),
('Iasi');
insert into Ruta(name, trainId) values
('Cluj-Sv', 1),
('Cluj-Iasi', 2),
('Sv-Iasi', 3);
insert into RutaStations(ruta, stationId, arrival, departure) values
('Cluj-Sv', 1, '20:00', '20:10'),
('Cluj-Iasi', 1, '21:00', '21:10'),
('Cluj-Iasi', 2, '03:00', '03:10'),
('Cluj-Iasi', 3, '06:00', '06:10');
-- Drop the stored procedure ex2
drop procedure proc1;

go
/*2. Implement a stored procedure that receives a route, a station, arrival and departure times, and adds the station to the route. 
If the station is already on the route, the departure and arrival times are updated.*/
create procedure proc1
	@route varchar(30), 
	@station varchar(30),
	@arrival time,
	@departure time
as
	begin
		declare @stationId int
		select @stationId = stationId from Station where name = @station

		if exists (select top 1 stationId from RutaStations where ruta = @route and stationId = @stationId)
			begin
				update RutaStations
				set arrival = @arrival, departure = @departure
				where ruta = @route and stationId = @stationId
			end
		else
			begin
				insert into RutaStations values (@route, @stationId, @arrival, @departure)
			end
	end;
go
exec proc1 @route='Cluj-Sv', @station='Cluj', @arrival='20:20', @departure='20:25'
select * from RutaStations
go
/*3. Create a view that shows the names of the routes that pass through all the stations.*/
drop view if exists view1
go
create view view1 
as
	select RS.ruta
	from RutaStations RS
	group by RS.ruta
	having count(distinct RS.stationId) = (select count(stationId) from Station);
go
select * from view1;
go
drop function if exists f4
go
/*4. Implement a function that lists the names of the stations with more than R routes, where R is a function parameter.*/
create function f4(@r int) returns table
as
	return
	select S.name
	from Station S
	inner join (
		select RS.stationId
		from RutaStations RS
		group by RS.stationId
		having count(RS.ruta) > @r
	) AS StationsWithMoreThanR on S.stationId = StationsWithMoreThanR.stationId;
go

select * from f4(1)