use pregateisan

DROP TABLE IF EXISTS TransactionAtm;
DROP TABLE IF EXISTS Transactioncard;
DROP TABLE IF EXISTS Transactions;
DROP TABLE IF EXISTS Atm;
DROP TABLE IF EXISTS AccountCards;
DROP TABLE IF EXISTS Card;
DROP TABLE IF EXISTS Account;
DROP TABLE IF EXISTS Customers;

create table Customers(
	Id int identity(1,1),
	name varchar(30),
	dateOfBirth time,
	primary key(Id));
create table Account(
	Iban int unique not null, 
	balance int,
	holder int, 
	primary key(Iban),
	foreign key(holder) references Customers(Id));
create table Card(
	nr int unique not null,
	ccv int unique not null,
	account int not null,
	primary key(nr),
	foreign key(account) references Account(Iban));
create table AccountCards(
	Iban int not null, 
	nr int not null,
	foreign key(nr) references card(nr),
	foreign key(Iban) references Account(Iban));
create table Atm(
	atmId int identity(1,1),
	adress varchar(50),
	primary key (atmId));
create table Transactions(
	transId int identity(1,1),
	suma int,
	timp time,
	primary key(transId));
create table Transactioncard(
	transId int,
	nr int,
	foreign key(transId) references Transactions(transId),
	foreign key(nr) references Card(nr));
create table TransactionAtm(
	transId int,
	atm int,
	foreign key(transId) references Transactions(transId),
	foreign key(atm) references Atm(atmId));

-- Insert into Customers table
INSERT INTO Customers (name, dateOfBirth) VALUES
('John Doe', '1990-01-01'),
('Jane Smith', '1985-05-15'),
('Bob Johnson', '1988-11-20');

-- Insert into Account table
INSERT INTO Account (Iban, balance, holder) VALUES
(123456789, 1000, 1),
(987654321, 500, 2),
(555555555, 1500, 3);

-- Insert into Card table
INSERT INTO Card (nr, ccv, account) VALUES
(111111, 123, 123456789),
(222222, 456, 987654321),
(333333, 789, 555555555);

-- Insert into AccountCards table
INSERT INTO AccountCards (Iban, nr) VALUES
(123456789, 111111),
(987654321, 222222),
(555555555, 333333);

-- Insert into Atm table
INSERT INTO Atm (adress) VALUES
('123 Main St'),
('456 Oak St'),
('789 Maple St');

-- Insert into Transactions table
INSERT INTO Transactions (suma, timp) VALUES
(500, '12:30:00'),
(1000, '15:45:00'),
(200, '09:00:00');

-- Insert into Transactioncard table
INSERT INTO Transactioncard (transId, nr) VALUES
(1, 111111),
(2, 222222),
(3, 333333);

-- Insert into TransactionAtm table
INSERT INTO TransactionAtm (transId, atm) VALUES
(1, 1),
(2, 2),
(3, 3);
go
/*stored procedure that receives a card and deletes all the transactions related*/
create procedure b
	@card int
as
begin
	declare @transaction int
	select top 1 @transaction=TransactionCard.transId from Transactioncard where Transactioncard.nr=@card
	while @transaction is not null
	begin
		delete from TransactionAtm where transId=@transaction
		delete from Transactioncard where transId=@transaction
		delete from Transactions where transId=@transaction
		select top 1 @transaction=TransactionCard.transId from Transactioncard where Transactioncard.nr=@card
	end
end;
go

exec b @card=111111;
select * from TransactionAtm;
go

/*view that shows the card numbers which were used at all atms*/
create view c
as
	select nou.nr from(
		select Card.nr, ta.atm from Card 
		join TransactionCard tc on card.nr=tc.nr
		join  TransactionAtm ta on ta.transId=tc.transId) as nou
	group by nou.nr
	having count(nou.atm)=(SELECT COUNT(*) FROM Atm);
go
select * from c

/* function that lists the cards that have the total transactions sum >200*/
go
create function d() returns table
as
	return
	(SELECT Card.nr, Card.ccv, SUM(Transactions.suma) as total_sum
    FROM Card 
    JOIN TransactionCard tc ON Card.nr = tc.nr
    JOIN Transactions ON tc.transId = Transactions.transId
    GROUP BY Card.nr, Card.ccv
    HAVING SUM(Transactions.suma) > 200);
go
select * from d();
