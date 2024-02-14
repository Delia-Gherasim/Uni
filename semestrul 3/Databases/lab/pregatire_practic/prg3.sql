use pregateisan

drop table if exists WomenShoes
drop table if exists Women
drop table if exists ShoeShop
drop table if exists Shop
drop table if exists ShoeModel
drop table if exists Shoes
drop table if exists Models
create table Shoes(
	shoeId int identity(1,1),
	price int,
	primary key(shoeId));
create table Models(
	modelId int identity(1,1),
	name varchar(30),
	season varchar(30),
	primary key(modelId));
create table ShoeModel(
	modelId int, 
	shoeId int,
	foreign key(modelId) references Models(modelId),
	foreign key(shoeId) references Shoes(shoeId));
create table Shop(
	shopId int identity(1,1),
	name varchar(30),
	city varchar(30),
	primary key(shopId));
create table ShoeShop(
	shoeId int,
	shopId int,
	available int,
	foreign key(shoeId) references Shoes(shoeId),
	foreign key(shopId) references Shop(shopId));
create table Women(
	womenId int identity(1,1),
	name varchar(30),
	amount int,
	primary key(womenId));
create table WomenShoes(
	womenId int,
	shoeId int,
	number int,
	spentAmount int,
	foreign key(womenId) references Women(womenId),
	foreign key(shoeId) references Shoes(shoeId));

-- Insert data into Shoes table
INSERT INTO Shoes (price) VALUES (50);
INSERT INTO Shoes (price) VALUES (80);
INSERT INTO Shoes (price) VALUES (120);

-- Insert data into Models table
INSERT INTO Models (name, season) VALUES ('Sneaker A', 'Spring');
INSERT INTO Models (name, season) VALUES ('Boot B', 'Winter');
INSERT INTO Models (name, season) VALUES ('Sandals C', 'Summer');

-- Insert data into ShoeModel table
INSERT INTO ShoeModel (modelId, shoeId) VALUES (1, 1);
INSERT INTO ShoeModel (modelId, shoeId) VALUES (2, 2);
INSERT INTO ShoeModel (modelId, shoeId) VALUES (3, 3);

-- Insert data into Shop table
INSERT INTO Shop (name, city) VALUES ('Shoe Emporium', 'New York');
INSERT INTO Shop (name, city) VALUES ('Fashion Feet', 'Los Angeles');
INSERT INTO Shop (name, city) VALUES ('Sole Haven', 'Chicago');

-- Insert data into ShoeShop table
INSERT INTO ShoeShop (shoeId, shopId, available) VALUES (1, 1, 10);
INSERT INTO ShoeShop (shoeId, shopId, available) VALUES (2, 2, 5);
INSERT INTO ShoeShop (shoeId, shopId, available) VALUES (3, 3, 8);

-- Insert data into Women table
INSERT INTO Women (name, amount) VALUES ('Alice', 200);
INSERT INTO Women (name, amount) VALUES ('Emma', 150);
INSERT INTO Women (name, amount) VALUES ('Olivia', 180);

-- Insert data into WomenShoes table
INSERT INTO WomenShoes (womenId, shoeId, number, spentAmount) VALUES (1, 1, 2, 100);
INSERT INTO WomenShoes (womenId, shoeId, number, spentAmount) VALUES (2, 2, 1, 80);
INSERT INTO WomenShoes (womenId, shoeId, number, spentAmount) VALUES (3, 3, 2, 240);

drop procedure if exists addShoe
go
create procedure addShoe
    @shoe int,
    @shop varchar(30),
    @number int
as
begin
    declare @shopId varchar(30)
    select @shopId = Shop.shopId from Shop where Shop.name = @shop

    if exists (select SS.available from ShoeShop SS where SS.shoeId = @shoe and SS.shopId = @shopId)
    begin
        update ShoeShop
        set available = available + @number
        where shoeId = @shoe and shopId = @shopId
    end
    else
    begin
        insert into ShoeShop (shoeId, shopId, available) values (@shoe, @shopId, @number)
    end
end;
go

-- Execute procedure
select * from ShoeShop
exec addShoe 1, 'Shoe Emporium', 10;
drop view if exists a3
go
create view a3 
as
	select Women.name from Women
	join WomenShoes on Women.womenId=WomenShoes.womenId
	where WomenShoes.number>=2;
go
select* from a3
drop function if exists a4
go
create function a4(@t int) returns table
as
	return
	select ShoeShop.shoeId, count(shopId) as shopCount from ShoeShop group by shoeId having count(shopId)>=@t;
go

select * from a4(1)

