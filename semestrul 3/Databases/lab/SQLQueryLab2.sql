use Concerts

alter table Bands add unique (bandName);
alter table Dj add unique (name);
alter table Effects add unique (concertId);
alter table Locations add unique (name);

/*insert data – for at least 4 tables*/
insert into Bands(bandName, vocalist, guitarist, basist, manager) values 
('Imagine Dragons', 'Dan Reynolds', 'Wayne Sermon', 'Ben McKee', 'Mac Reynolds'),
('Ava Max', 'Ava Max', NULL,NULL ,'Allison Kaye'),
('Irina Rimes', 'Irina Rimes', NULL, NULL, 'Elena Broost'),
('Satra Benz', 'Killa fonic, Nosfe', NULL, NULL, 'Luca George'),
('Bosquito', 'Radu Almășan', 'Ciprian Pascal', 'Mircea “Burete” Preda', 'Ionut Contras'),
('Vama', 'Tudor Chirilă', ' Eugen Caminschi', 'Lucian Cioargă', 'Dan Opriș'),
('Cargo', 'Adrian Ingrisan', 'David Cristian', 'Alin Achim', 'Octavian Pilan'),
('Ada Milea', 'Ada Milea', 'Alex Balanescu', NULL, 'Ada Milea'),
('Macklemore', 'Benjamin Hammond Haggerty', null, null, 'Ben Secord'),
('George Ezra', 'George Ezra Barnett ', 'George Ezra Barnett ', null,'Ryan Lofthouse'),
('Nothing but Thieves','Conor Mason', 'Joe Langridge', 'Philip Blake','Stefanie Reines'),
('Subcarpati', 'Alexe Marius Andrei', 'Vali Umbră', 'Radu Pieloiu', 'Cristian Tache'),
('Coma', 'Cătălin Chelemen', 'Dan Costea', 'Matei Tibacu-Blendea', 'Sorin Petrescu'),
('Nova Twins', 'Amy Love', 'Amy Love', 'Georgia South', 'Nina Leighton'),
('ASIA', 'Anca, Sorana, Irina, Anemona', null, null, 'Florin Ionescu');

/* at least one statement must violate referential integrity constraints
insert into Bands(bandId, bandName, vocalist, guitarist,basist, manager) values
(10, NULL, 'Aa', NULL, NULL, 'NULL'); */

insert into Dj(name, stageName) values
('Steven Hiroyuki Aoki','Steve Aoki'),
('Emir Kobilić', 'Salvatore Ganacci'),
('Alessandro Lindblad', 'Alesso'),
('Matthias Richter', 'Tujamo'),
('Răzvan Rădulescu', 'Dj Hefe');

insert into Concert(bandId, fans, date, startTime, endTime) values 
(1, 30999, '2023-08-04', '22:10:00', '23:40:00'),
(2, 10000, '2023-08-03', '20:35:00', '21:35:00'),
(3, 7000, '2023-08-03', '19:20', '20:10'),
(4, 5000, '2023-08-04', '22:40', '23:25'), 
(4, 900, '2023-08-04', null, null),
(5, 900, '2023-08-03',null,null),
(6, 900, '2023-08-04',null,null),
(6, 1000, '2023-08-06', '19:15', '20:00'),
(7, 900, '2023-08-03', null, null),
(8, 900, '2023-10-02', '20:00', '22:00'),
(9, 25000, '2023-07-20', '23:40', '00:00'),
(10, 9000, '2023-07-20', '22:05', '23:30'),
(11, 9000, '2023-07-22', '19:40', '21:50'),
(12, 8500, '2023-07-23', '22:40', '00:00'),
(14, 16000, '2023-07-23', '20:30', '21:40'),
(15, 6000, '2023-07-20','19:00', '20:30');

insert into Concert(bandId, djId, fans, date, startTime, endTime) values
(13, 5, 8500, '2023-07-21', '18:30','19:40');

insert into Concert(djId, fans, date, startTime, endTime) values
(1, 10000, '2023-08-03', '03:00:00','04:15:00'),
(2, 13000, '2023-08-04', '00:00', '01:30'),
(3, 9000, '2023-08-04', '02:00', '03:30'),
(4, 15000, '2023-08-04', '03:50', '06:00');

insert into Effects(concertId, fireworks, lasers, projectorScreen) values
(1, 1, 0, 1),
(2, 0, 1, 1),
(3, 1, 0, 1),
(4, 1, 1,1 ),
(5, 0, 0, 1),
(6, 0, 0, 1),
(7, 0, 0, 1),
(8, 0, 0, 0);

insert into Locations(name, addres, streetNumber, city) values
('Parcul Central', 'Parcul Central Simion Barnutiu', NULL, 'Cluj-Napoca'),
('Cluj Arena', 'Aleea Stadionului', 2,'Cluj-Napoca'),
('Form Space', 'Aleea Stadionului', 2,'Cluj-Napoca'),
('Sala Polivalenta', 'Strada Uzinei Electrice',NULL, ' Cluj-Napoca'),
('Banffy Castle', 'DJ161', NULL, 'Bonțida'),
('Euphoria Music Hall', 'Calea Mănăștur', 6, 'Cluj-Napoca'),
('Flying Circus', 'Piața Unirii' ,21, 'Cluj-Napoca');

insert into Event(eventName, concertId, locationId, organizer, staff) values
('Untold', 1, 2, 'Bogdan Buta',  300),
('Untold', 2, 2, 'Bogdan Buta', 200),
('Untold', 3, 2, 'Bogdan Buta', 150),
('Untold', 6, 2, 'Bogdan Buta', 150),
('Untold', 9, 4, 'Bogdan Buta', 250),
('Untold', 10, 4, 'Bogdan Buta', 250),
('Untold', 11, 4, 'Bogdan Buta', 250),
('Untold', 12, 4, 'Bogdan Buta', 250),
('Untold', 13, 4, 'Bogdan Buta', 250),
('Electric Castle', 11, 5, 'Katalin Banffy', 250),
('Electric Castle', 12, 5, 'Katalin Banffy', 250),
('Electric Castle', 13, 5, 'Katalin Banffy', 250),
('Electric Castle', 14, 5, 'Katalin Banffy', 250),
('Electric Castle', 15, 5, 'Katalin Banffy', 250),
('Electric Castle', 16, 5, 'Katalin Banffy', 250);

insert into Participants(participantCNP, name, surname, dateOfBirth) values
(123456789, 'John', 'Smith', '1980-05-15'),
(987654321, 'Emily', 'Johnson', '1992-12-30'),
(555555555, 'Michael', 'Brown', '1988-08-21'),
(888877776, 'Sarah', 'Davis', '1995-04-10'),
(111122223, 'Robert', 'Wilson', '1983-07-03'),
(999988887, 'Jennifer', 'Lee', '1990-11-17'),
(444433332, 'David', 'Martinez', '1987-02-25'),
(666655557, 'Jessica', 'Anderson', '1998-09-12'),
(222211113, 'William', 'Clark', '1986-06-28'),
(777766664, 'Amanda', 'White', '1993-03-08');

insert into Staff(staffCNP, name, surname, department, hoursWorked, salary) values
(123456789, 'John', 'Smith', 'Security', 40, 400),
(987654321, 'Emily', 'Johnson', 'Stage Crew', 35, 350),
(555555555, 'Michael', 'Brown', 'Sound Engineer', 45, 450),
(888877776, 'Sarah', 'Davis', 'Event Coordinator', 40, 500),
(111122223, 'Robert', 'Wilson', 'Ticket Sales', 30, 300),
(999988887, 'Jennifer', 'Lee', 'Food Vendor', 25, 250),
(444433332, 'David', 'Martinez', 'Lighting Technician', 35, 350),
(666655557, 'Jessica', 'Anderson', 'Stage Manager', 40, 450),
(222211113, 'William', 'Clark', 'First Aid', 30, 320),
(777766664, 'Amanda', 'White', 'Merchandise Sales', 25, 270);

/*update data – for at least 3 tables*/
update Dj set name='unknown' where djId=5;
update Bands set manager=' Peter Saler ' where bandName='Irina Rimes';
update Locations set name='BT Arena' where addres='Strada Uzinei Electrice';

/*delete data – for at least 2 tables*/
delete from Effects where fireworks=0 and projectorScreen=0;
delete from Concert where fans<500;

/*2 queries with the union operation; use UNIon [ALL] and OR*/
select bandId from Bands
union all
select bandId from Concert;

select concertId from Effects where projectorScreen=1 or fireworks=1
union
select concertId from Concert

/*2 queries with the intersection operation; use INTERSECT and IN*/
select bandId from Bands
intersect
select bandId from Concert;

select * from Dj where djId 
in (select djId from Concert where Concert.date>'2023-08-03');

/*2 queries with the difference operation; use EXCEPT and NOT IN*/
select bandId from Bands 
except
select bandId from Concert where fans <1000

select * from Locations where locationId 
not in (
select locationId from Event where eventName='Untold');

/* 4 queries with inner join, LEFT join, RIGHT join, and FULL join (one query per operator); 
one query will join at least 3 tables, while another one will join at least two many-to-many relationships;*/
select Effects.fireworks, Event.eventName from Effects
inner join Concert on Effects.concertId = Concert.concertId
inner join Event on Concert.concertId = Event.concertId
where Event.locationId = 2;

select bandName, vocalist from Bands
left join Concert on Bands.bandId=Concert.bandId where Concert.fans>1000;

select Event.locationId, eventName, eventId from Event
right join Locations on Locations.locationId=Event.locationId

select EventStaff.eventId, participantConcert.concertID, participantConcert.participantCNP from EventStaff
join Event on EventStaff.eventId=Event.eventId
join participantConcert on Event.concertId=participantConcert.concertID

/*2 queries with the IN operator and a subquery in the where clause; 
in at least one case, the subquery must include a subquery in its own where clause;*/
select * from Bands where Bands.bandId
in (select Concert.bandId from Concert);

select * from Effects where Effects.concertId
in (select Concert.concertId from Concert where Concert.concertId 
	in (select Event.concertId from Event where Event.eventName='Untold'));

/*2 queries with the EXISTS operator and a subquery in the where clause;*/
select Bands.bandId, Bands.bandName, Bands.vocalist from Bands
where exists (select Concert.bandId from Concert where Concert.fans>10000);

select Concert.date, Concert.startTime from Concert
where exists (select Event.concertId from Event where Event.eventName='Untold');

/*2 queries with a subquery in the from clause*/
select b.bandName from 
	(select Bands.bandName from Bands where Bands.bandId%2=0) as b

select name, surname from 
	(select	name, surname, department from Staff 
	inner join EventStaff on Staff.staffCNP=EventStaff.staffCNP and EventStaff.eventId=2) as a

/*4 queries with the group by clause, 
3 of which also contain the having clause; 
2 of the latter will also have a subquery in the having clause;
use the aggregation operators: count, SUM, AVG, min, max*/

select Concert.bandId, count(Concert.date) as countDate from Concert
group by Concert.bandId order by countDate desc;

select Concert.bandId, count(Concert.fans) as countFans from Concert
group by Concert.bandId having count(Concert.fans) > 100;

select eventId, eventName, max(staff) as maxStaff from Event
group by eventId, eventName having max(staff) > 50;

select bandId, count(*) as totalConcerts from Concert
group by bandId having count(*) > 3;

/*4 queries using ANY and ALL to introduce a subquery in the where clause (2 queries per operator); */
select bandId, bandName from Bands where bandId = ANY (
    select bandId from Concert where fans > ALL (
        select max(fans) from Concert ));

select concertId, fans from Concert where fans > ANY (
    select min(fans) from Concert);

select bandId, bandName from Bands where bandId = ALL (
    select bandId from Concert where fans < ALL (
        select min(fans) from Concert));

select concertId, fans from Concert where fans < ALL (
    select max(fans) from Concert);

/*rewrite 2 of them with aggregation operators, and the other 2 with IN / [NOT] IN.*/
select bandId, bandName from Bands where bandId = ANY (
    select bandId from Concert group by bandId 
	having max(fans) < ALL (
        select max(fans) from Concert));

select concertId, fans from Concert where fans > ANY (
    select min(fans) from Concert group by bandId);

select bandId, bandName from Bands where bandId IN (
    select bandId from Concert where fans < ALL (
        select min(fans) from Concert));

select concertId, fans from Concert where fans < ALL (
    select max(fans) from Concert where bandId NOT IN (
        select bandId from Bands));
