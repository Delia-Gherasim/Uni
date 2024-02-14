use Concerts
--Ta: Concert(concertId, fans, ...)
--Tb: Locations(locationId, streetNumber, ...)
--Tc: Event(eventId, locationId, concertId, ...)

execute sp_helpindex Concert -- => pk concertId = clustered index
/* on Ta */ 
--clustered index scan;
select * from Concert order by concertId desc;

--clustered index seek;
select Concert.date, Concert.fans, Concert.concertId from Concert where Concert.concertId=1;

--nonclustered index scan;
create nonclustered index ind on Concert(fans);
update statistics Concert;
select * from Concert with (index(ind)) order by fans asc;

--nonclustered index seek;
select * from Concert with (index(ind)) where fans between 100 and 10000;

--key lookup.
select Concert.date, Concert.bandId, Concert.djId from Concert with (index(ind)) where  concertId=100 and fans=100

/* on Tb */
-- Write a query on table Tb with a WHERE clause of the form WHERE b2 = value and analyze its execution plan. 
select Locations.name, Locations.addres from Locations where streetNumber=3 --it has a clustered index scan with cost 100%

--Create a nonclustered index that can speed up the query. Examine the execution plan again.
create nonclustered index indx on Locations(streetNumber);
select Locations.name, Locations.addres from Locations with (index(indx)) where streetNumber=3 --it has an index seek with cost 50% and key lookup with cost 50% execution plan

/**/
-- Create a view that joins at least 2 tables. Check whether existing indexes are helpful; if not, reassess existing indexes / examine the cardinality of the tables.
go
create view view4 as
	select Event.locationId, Event.concertId, Event.organizer, Locations.name from Event 
	join Locations on Locations.locationId= Event.locationId;
go
--execution plan: clustered index scan 50% on Event.eventId (primary key => clustered index)
--				  clustered index seek 50% on Location.locationId (primary key => clustered index) 