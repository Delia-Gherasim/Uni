use pregateisan
drop table if exists ProdMovies
drop table if exists ProdActors
drop table if exists CinemaProd
drop table if exists Movies
drop table if exists Director
drop table if exists Company
drop table if exists Actors
create table Actors(
	actorId int identity(1,1),
	name varchar(30),
	ranc int,
	primary key(actorId));
create table Company(
	compId int identity(1,1),
	name varchar(30),
	primary key(compId));
create table Director(
	directorId int identity(1,1),
	name varchar(30),
	awards int,
	PRIMARY KEY(directorId));
create table Movies(
	movieId int identity(1,1),
	name varchar(30),
	release date,
	compId int,
	directorId int,
	primary key(movieId),
	foreign key(compId) references Company(compId),
	foreign key(directorId) references Director(directorId));
create table CinemaProd(
	prodId int identity(1,1),
	title varchar(30),
	movieId int, 
	primary key(prodId),
	foreign key(movieId) references Movies(movieId));
create table ProdActors(
	actorId int,
	prodId int ,
	entry time,
	foreign key(actorId) references Actors(actorId),
	foreign key(prodId) references CinemaProd(prodId));
create table ProdMovies(
	movieId int,
	prodId int,
	foreign key(movieId) references Movies(movieId),
	foreign key(prodId) references CinemaProd(prodid));

insert into Actors(name, ranc) values('a1', 100),('a2', 98),('a3', 80);
insert into Company(name) values ('c1'),('c2'),('c3');
insert into Director(name, awards) values ('d1', 7),('d2', 4),('d3', 5);
insert into Movies(name, release, compId, directorId) values
('m1', '01.01.2021',1, 1),
('m2', '02.02.2022', 2, 2),
('m3', '03.03.2023', 3, 3),
('m3', '04.04.2024', 1, 1);
insert into CinemaProd(title, movieId) values 
('t1', 1),
('t2', 2),
('t3', 1),
('t4', 4);
insert into ProdActors(actorId, prodId, entry) values
(1,1,'02:02'),
(2, 2, '02:03'),
(1, 2, '02:04'),
(3, 4, '00:04'),
(1, 3, '00:05'),
(1, 4, '00:10');

drop procedure if exists proc4
go
create procedure proc4
	@actor varchar(30),
	@entry time,
	@cinemaProd int
	as
	begin
	declare @actorId int
	select @actorId=Actors.actorId from Actors where Actors.name=@actor
	if exists(select ProdActors.actorId from ProdActors where ProdActors.actorId=@actorId and ProdActors.prodId=@cinemaProd)
		begin
		update ProdActors
		set entry=@entry
		where ProdActors.actorId=@actorId and ProdActors.prodId=@cinemaProd
		end
	else
		begin
		insert into ProdActors(actorId, prodId, entry) values(@actorId, @cinemaProd, @entry)
		end
	end;

go
exec proc4 @actor='a1', @entry='02:31', @cinemaProd=3
select * from ProdActors 

drop view if exists view4
go
create view view4 
as
	select Actors.actorId from Actors
	join(
	select ProdActors.actorId from ProdActors
	group by ProdActors.actorId
	having count(ProdActors.prodId)=(select count(CinemaProd.prodId) from CinemaProd) )as nou
	on nou.actorId=Actors.actorId

go
select * from view4
drop function if exists f4
go
create function f4( @p int) returns table
as
	return(
	select Movies.name from Movies 
	join (
		select ProdMovies.movieId from ProdMovies
		group by ProdMovies.movieId
		having count(ProdMovies.prodId)>=@p
	) as nou
	on Movies.movieId=nou.movieId 
	where Movies.release>'01.01.2018');
go
select * from f4(1);