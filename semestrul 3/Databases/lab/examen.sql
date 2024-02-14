use test

drop table if exists BookingPayments
drop table if exists Payments
drop table if exists Booking
drop table if exists Properties
drop table if exists CustomersEmail
drop table if exists Customers

create table Customers(
	customerId int identity(1,1),
	username varchar(30) unique,
	nationality varchar(30),
	dateOfBirth date,
	primary key(customerId));
create table CustomersEmails(
	customerId int, 
	email varchar(50),
	foreign key(customerId) references Customers(customerId));
create table Properties(
	propId int identity(1,1),
	name varchar(30),
	descr varchar(100),
	adr varchar(50),
	checkIn time,
	checkOut time,
	nrOfPeople int,
	price int,
	cancelation bit,
	primary key(propId));
create table Bookings(
	bookingId int identity(1,1),
	propId int,
	customerId int,
	startDate date,
	endDate date,
	primary key(bookingId),
	foreign key(propId)references Properties(propId),
	foreign key(customerId)references Customers(customerId));
create table Payments(
	paymentId int identity(1,1),
	amount int,
	dateOf date,
	payType varchar(30),
	primary key(paymentId));
create table BookingPayments(
	paymentId int,
	bookingId int,
	foreign key(paymentId) references Payments(paymentId),
	foreign key(bookingId) references Bookings(bookingId));


insert into Customers(username, dateOfBirth, nationality) values
('c1', '01.01.2001', 'ro'),
('c2', '01.01.2001', 'ro'),
('c3', '01.01.2001', 'ro'),
('c4', '01.01.2001', 'ro'),
('c5', '01.01.2001', 'ro');
insert into CustomersEmails(customerId, email) values
(1, 'email'),
(1, 'email'),
(2, 'email'),
(2, 'email'),
(3, 'email');
insert into Properties(name, price) values
('n1', 200),('n2', 300),('n3', 150),('n4', 200);
insert into Bookings(customerId, propId) values
(1,1),(1,2),(1,3),(1,4),(2,1),(3,2),(3,3),(3,4);
insert into Payments(amount, dateOf, payType) values
(100, '01.01.2001', 'PayPal'),
(50, '01.01.2001', 'PayPal'),
(10, '01.01.2001', 'PayPal'),
(200, '01.01.2001', 'online'),
(100, '01.01.2001', 'online'),
(100, '01.01.2001', 'online');
insert into BookingPayments(bookingId, paymentId) values
(1, 2), (2, 1),(2,3),(2, 4);


drop procedure if exists ex2
go

create procedure ex2
	@bookId int,
	@amount int,
	@date date,
	@payType varchar(30)
	as
	begin
		declare @totalAmount int
		select @totalAmount=sum(Payments.amount) from  Payments
		join BookingPayments on Payments.paymentId=BookingPayments.paymentId 
		where bookingId=@bookId
		group by bookingId 

		declare @price int
		select @price=Properties.price from Properties
		join Bookings on Properties.propId=Bookings.bookingId
		where bookingId=@bookId

		if @totalAmount+@amount<=@price
		begin
			declare @payId int
			insert into Payments(amount, dateOf, payType) values (@amount, @date, @payType)
			select @payId=Payments.paymentId from Payments where amount=@amount and dateOf=@date and payType=@payType
			insert into BookingPayments(paymentId, bookingId) values(@payId, @bookId)
		end
		else
			print('Amount exceeded')
	end;
go

exec ex2 @bookId=1, @amount=8, @date='10.10.2023', @payType='online'
select * from Payments

drop view if exists ex3
go
create view ex3
	as
	select Customers.username
	from Customers
	join (
		select top 1 with ties Bookings.customerId
		from Bookings
		group by customerId
		order by count(bookingId) desc
	) as maxBookings on maxBookings.customerId = Customers.customerId;
go

select * from ex3;

drop function if exists ex4
go

create function ex4(@r int) returns table
as
	return (
		select count(Bookings.bookingId) as coloana from Bookings
		join BookingPayments on BookingPayments.bookingId=Bookings.bookingId
		join Payments on BookingPayments.paymentId= Payments.paymentId
		where Payments.payType='PayPal'
		group by Bookings.customerId having count(Bookings.bookingId)<@r
		)
go
select * from ex4(8)