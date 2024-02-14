use pregateisan
drop table if exists CakeOrders
drop table if exists Chefcakes
drop table if exists Orders
drop table if exists Chef
drop table if exists Cakes
drop table if exists cTypes

create table cTypes(
	typeId int identity(1,1),
	name varchar(30),
	descr varchar(50),
	primary key(typeId));
create table Cakes(
	cakeId int identity(1,1),
	name varchar(30),
	shape varchar(30),
	weight int,
	price int,
	typeId int,
	foreign key(typeId) references cTypes(typeId),
	primary key(cakeId));
create table Chef(
	chefId int identity(1,1),
	name varchar(30),
	gender varchar(30),
	dateBirth date,
	primary key(chefId));
create table Orders(
	orderId int identity(1,1),
	dateOrder date,
	primary key(orderId));
create table Chefcakes(
	chefId int,
	cakeId int,
	foreign key(chefId) references Chef(chefId),
	foreign key(cakeId) references Cakes(cakeId));
create table CakeOrders(
	cakeId int,
	orderId int,
	number int
	foreign key(cakeId) references Cakes(cakeId),
	foreign key(orderId) references Orders(orderId));

insert into cTypes(name) values
('t1'),('t2'),('t3'),('t4');
insert into Cakes(name, typeId) values
('c1', 1),
('c2', 1),
('c3', 2),
('c4', 3);
insert into Chef(name) values
('chef1'),('chef2'),('chef3'),('chef4'),('chef5');
insert into Orders(dateOrder) values
('02.02.2024'),('11.11.2011'),('10.10.2023');
insert into Chefcakes(chefId, cakeId) values
(1, 1),(1, 2),(1, 3), (2, 3),(2, 4),(5, 1),(5, 2),(5, 3),(5, 4);
insert into CakeOrders(cakeId, orderId) values
(1,1),(1, 2), (1, 3), (2, 1),(2,3),(3,2),(4, 3),(4,2),(4,1);

drop procedure if exists proc5 
go
create procedure proc5
	@orderId int,
	@cake varchar(30),
	@p int
as
begin
	declare @cakeId int
	select @cakeId=Cakes.cakeId from Cakes where Cakes.name=@cake
	if exists(select CO.cakeId from CakeOrders CO where CO.orderId=@orderId and CO.cakeId=@cakeId)
		begin
		update CakeOrders 
		set number=@p
		where orderId=@orderId and cakeId=@cakeId
		end;
	else
		begin
		insert into CakeOrders(cakeId, orderId, number) values(@cakeId, @orderId, @p)
		end;
	end
go
exec proc5 @orderId=1, @cake='c1', @p=51
select * from CakeOrders

drop function if exists f5
go
create function f5() returns table
as
	return(
		select Chef.name from Chef
		join( 
			select Chefcakes.chefId from Chefcakes
			group by Chefcakes.chefId
			having count(Chefcakes.cakeId)=(select count(cakeId) from Cakes)	)
			as nou
		on nou.chefId=Chef.chefId 	)
go

select * from f5()