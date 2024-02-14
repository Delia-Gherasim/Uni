use Concerts
if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestRunTables_Tables]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [TestRunTables] DROP CONSTRAINT FK_TestRunTables_Tables
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestTables_Tables]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [TestTables] DROP CONSTRAINT FK_TestTables_Tables
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestRunTables_TestRuns]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [TestRunTables] DROP CONSTRAINT FK_TestRunTables_TestRuns
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestRunViews_TestRuns]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [TestRunViews] DROP CONSTRAINT FK_TestRunViews_TestRuns
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestTables_Tests]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [TestTables] DROP CONSTRAINT FK_TestTables_Tests
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestViews_Tests]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [TestViews] DROP CONSTRAINT FK_TestViews_Tests
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestRunViews_Views]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [TestRunViews] DROP CONSTRAINT FK_TestRunViews_Views
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestViews_Views]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [TestViews] DROP CONSTRAINT FK_TestViews_Views
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[Tables]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [Tables]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[TestRunTables]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [TestRunTables]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[TestRunViews]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [TestRunViews]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[TestRuns]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [TestRuns]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[TestTables]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [TestTables]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[TestViews]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [TestViews]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[Tests]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [Tests]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[Views]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [Views]
GO

CREATE TABLE [Tables] (
	[TableID] [int] IDENTITY (1, 1) NOT NULL ,
	[Name] [nvarchar] (50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [TestRunTables] (
	[TestRunID] [int] NOT NULL ,
	[TableID] [int] NOT NULL ,
	[StartAt] [datetime] NOT NULL ,
	[EndAt] [datetime] NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [TestRunViews] (
	[TestRunID] [int] NOT NULL ,
	[ViewID] [int] NOT NULL ,
	[StartAt] [datetime] NOT NULL ,
	[EndAt] [datetime] NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [TestRuns] (
	[TestRunID] [int] IDENTITY (1, 1) NOT NULL ,
	[Description] [nvarchar] (2000) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[StartAt] [datetime] NULL ,
	[EndAt] [datetime] NULL 
) ON [PRIMARY]
GO

CREATE TABLE [TestTables] (
	[TestID] [int] NOT NULL ,
	[TableID] [int] NOT NULL ,
	[NoOfRows] [int] NOT NULL ,
	[Position] [int] NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [TestViews] (
	[TestID] [int] NOT NULL ,
	[ViewID] [int] NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [Tests] (
	[TestID] [int] IDENTITY (1, 1) NOT NULL ,
	[Name] [nvarchar] (50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [Views] (
	[ViewID] [int] IDENTITY (1, 1) NOT NULL ,
	[Name] [nvarchar] (50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL 
) ON [PRIMARY]
GO

ALTER TABLE [Tables] WITH NOCHECK ADD 
	CONSTRAINT [PK_Tables] PRIMARY KEY  CLUSTERED 
	([TableID])  ON [PRIMARY] 
GO

ALTER TABLE [TestRunTables] WITH NOCHECK ADD 
	CONSTRAINT [PK_TestRunTables] PRIMARY KEY  CLUSTERED (
		[TestRunID],
		[TableID]	)  ON [PRIMARY] 
GO

ALTER TABLE [TestRunViews] WITH NOCHECK ADD 
	CONSTRAINT [PK_TestRunViews] PRIMARY KEY  CLUSTERED 	(
		[TestRunID],
		[ViewID] )  ON [PRIMARY] 
GO

ALTER TABLE [TestRuns] WITH NOCHECK ADD 
	CONSTRAINT [PK_TestRuns] PRIMARY KEY  CLUSTERED 	(
			[TestRunID]	)  ON [PRIMARY] 
GO

ALTER TABLE [TestTables] WITH NOCHECK ADD 
	CONSTRAINT [PK_TestTables] PRIMARY KEY  CLUSTERED 	(
		[TestID],
		[TableID])  ON [PRIMARY] 
GO

ALTER TABLE [TestViews] WITH NOCHECK ADD 
	CONSTRAINT [PK_TestViews] PRIMARY KEY  CLUSTERED	(
		[TestID],
		[ViewID])  ON [PRIMARY] 
GO

ALTER TABLE [Tests] WITH NOCHECK ADD 
	CONSTRAINT [PK_Tests] PRIMARY KEY  CLUSTERED ([TestID])  ON [PRIMARY] 
GO

ALTER TABLE [Views] WITH NOCHECK ADD 
	CONSTRAINT [PK_Views] PRIMARY KEY  CLUSTERED ([ViewID])  ON [PRIMARY] 
GO

ALTER TABLE [TestRunTables] ADD 
	CONSTRAINT [FK_TestRunTables_Tables] FOREIGN KEY ([TableID]) REFERENCES [Tables] ([TableID]) ON DELETE CASCADE  ON UPDATE CASCADE ,
	CONSTRAINT [FK_TestRunTables_TestRuns] FOREIGN KEY([TestRunID]	) REFERENCES [TestRuns] ([TestRunID]) ON DELETE CASCADE  ON UPDATE CASCADE 
GO

ALTER TABLE [TestRunViews] ADD 
	CONSTRAINT [FK_TestRunViews_TestRuns] FOREIGN KEY ([TestRunID]) REFERENCES [TestRuns] ([TestRunID]) ON DELETE CASCADE  ON UPDATE CASCADE ,
	CONSTRAINT [FK_TestRunViews_Views] FOREIGN KEY ([ViewID]) REFERENCES [Views] ([ViewID]) ON DELETE CASCADE  ON UPDATE CASCADE 
GO

ALTER TABLE [TestTables] ADD 
	CONSTRAINT [FK_TestTables_Tables] FOREIGN KEY ([TableID]) REFERENCES [Tables] ([TableID]) ON DELETE CASCADE  ON UPDATE CASCADE ,
	CONSTRAINT [FK_TestTables_Tests] FOREIGN KEY ([TestID]) REFERENCES [Tests] ([TestID]) ON DELETE CASCADE  ON UPDATE CASCADE 
GO

ALTER TABLE [TestViews] ADD 
	CONSTRAINT [FK_TestViews_Tests] FOREIGN KEY ([TestID]) REFERENCES [Tests] ([TestID]),
	CONSTRAINT [FK_TestViews_Views] FOREIGN KEY ([ViewID]) REFERENCES [Views] (	[ViewID])
GO

drop View if exists View1
drop View if exists View2
drop View if exists View3
drop procedure if exists TestView
drop procedure if exists TestDelete
drop procedure if exists TestInsert
go 

create View View1 as
	select Concert.bandId, count(Concert.date) as countDate from Concert
	group by Concert.bandId ;
go

create View View2 as 
select EventStaff.eventId, participantConcert.concertID, participantConcert.participantCNP from EventStaff
join Event on EventStaff.eventId=Event.eventId
join participantConcert on Event.concertId=participantConcert.concertID;
go

CREATE VIEW View3 AS
SELECT Concert.bandId, COUNT(Concert.date) AS countDate
FROM Concert
INNER JOIN Event ON Concert.concertId = Event.concertId
GROUP BY Concert.bandId;
go

insert into [Views](Name) values
('View1'),('View2'),('View3');

insert into [Tables](Name) values
('Bands'),('Concert'),('EventStaff');

use Concerts
go

create procedure TestView
as
begin
	DECLARE @StartTime DATETIME;
	DECLARE @EndTime DATETIME;
	DECLARE @RowCount INT;
	DECLARE @testRunRowCount INT;
	insert into Tests(Name) values ('Test Views');
	SELECT @RowCount = COUNT(*) FROM Tests;
	
	SET @StartTime = GETDATE();
	SELECT * FROM View1;
	set @EndTime=getDate();
	insert into TestRuns(Description, StartAt, EndAt) values ('View 1 test run', @StartTime, @EndTime);
	SELECT @testRunRowCount = COUNT(*) FROM TestRuns;
	insert into TestViews(TestID, ViewID) values (@RowCount, 1);
	insert into TestRunViews(TestRunID, ViewID, StartAt, EndAt) values(@testRunRowCount,1, @StartTime, @EndTime);

	SET @StartTime = GETDATE();
	SELECT * FROM View2;
	set @EndTime=getDate();
	insert into TestRuns(Description, StartAt, EndAt) values ('View 2 test run', @StartTime, @EndTime);
	SELECT @testRunRowCount = COUNT(*) FROM TestRuns;
	insert into TestViews(TestID, ViewID) values (@RowCount, 2);
	insert into TestRunViews(TestRunID, ViewID, StartAt, EndAt) values(@testRunRowCount, 2, @StartTime, @EndTime);

	SET @StartTime = GETDATE();
	SELECT * FROM View3;
	set @EndTime=getDate();
	insert into TestRuns(Description, StartAt, EndAt) values ('View 3 test run', @StartTime, @EndTime);
	SELECT @testRunRowCount = COUNT(*) FROM TestRuns;
	insert into TestViews(TestID, ViewID) values (@RowCount, 3);
	insert into TestRunViews(TestRunID, ViewID, StartAt, EndAt) values(@testRunRowCount, 3, @StartTime, @EndTime);

end;
go

create procedure TestInsert
as
begin
	DECLARE @TestNr INT;
	DECLARE @StartTime DATETIME;
	declare @EndTime DATETIME;
	DECLARE @testRunRowCount INT;
	insert into Tests(Name) values ('Test Insert');
	SELECT @TestNr = COUNT(*) FROM Tests;
	
	SET @StartTime = GETDATE();
	DECLARE @Counter INT;
	SET @Counter = 1;
	WHILE @Counter <= 1000
	BEGIN
		 insert into Bands(bandName, vocalist, guitarist, basist, manager) values 
		('Imagine Dragons', 'Dan Reynolds', 'Wayne Sermon', 'Ben McKee', 'Mac Reynolds');
        SET @Counter = @Counter + 1;
	END;
	set @EndTime=getDate();
	insert into TestTables(TestID, TableID, NoOfRows,Position) values(@TestNr, 1, 1000, 1);
	insert into TestRuns(Description, StartAt, EndAt) values ('insert in table Bands', @StartTime, @EndTime);
	SELECT @testRunRowCount = COUNT(*) FROM TestRuns;
	insert into TestRunTables(TestRunID, TableID, StartAt, EndAt) values(@testRunRowCount, 1, @StartTime, @EndTime);


	SET @StartTime = GETDATE();
	SET @Counter = 1;
	WHILE @Counter <= 1000
	BEGIN
        INSERT INTO Concert(bandId,  fans, date, startTime, endTime)
		VALUES (1, 1,'2000-01-01', '00:00:00', '23:59:59'); 
        SET @Counter = @Counter + 1;
	END;
	set @EndTime=getDate();
	insert into TestTables(TestID, TableID, NoOfRows,Position) values(@TestNr, 2, 1000, 1);
	insert into TestRuns(Description, StartAt, EndAt) values ('insert in table Concert', @StartTime, @EndTime);
	SELECT @testRunRowCount = COUNT(*) FROM TestRuns;
	insert into TestRunTables(TestRunID, TableID, StartAt, EndAt) values(@testRunRowCount, 2, @StartTime, @EndTime);

	SET @StartTime = GETDATE();
	SET @Counter = 1;
	WHILE @Counter <= 1000
	BEGIN
        INSERT INTO EventStaff(eventId, staffCNP)
		VALUES (3, 111122223); 
        SET @Counter = @Counter + 1;
	END;
	set @EndTime=getDate();
	insert into TestTables(TestID, TableID, NoOfRows,Position) values(@TestNr, 3, 1000, 1);
	insert into TestRuns(Description, StartAt, EndAt) values ('insert in table EventStaff', @StartTime, @EndTime);
	SELECT @testRunRowCount = COUNT(*) FROM TestRuns;
	insert into TestRunTables(TestRunID, TableID, StartAt, EndAt) values(@testRunRowCount, 3, @StartTime, @EndTime);

	delete from Bands
	delete from Concert
	delete from EventStaff
end;
go

create procedure TestDelete
as
begin
	DECLARE @TestNr INT;
	DECLARE @StartTime DATETIME;
	declare @EndTime DATETIME;
	DECLARE @testRunRowCount INT;
	insert into Tests(Name) values ('Test Delete');
	SELECT @TestNr = COUNT(*) FROM Tests;

	DECLARE @Counter INT;
	SET @Counter = 1;
	WHILE @Counter <= 1000
	BEGIN
        insert into Bands(bandName, vocalist, guitarist, basist, manager) values 
		('Imagine Dragons', 'Dan Reynolds', 'Wayne Sermon', 'Ben McKee', 'Mac Reynolds');
        SET @Counter = @Counter + 1;
	END;
	INSERT INTO Bands(bandName, vocalist, guitarist, basist, manager) VALUES (' ',' ' , ' ', ' ',' '); 
	SET @Counter = 1;
	WHILE @Counter <= 1000
	BEGIN
        INSERT INTO Concert(bandId,  fans, date, startTime, endTime)
		VALUES (@Counter, 1,'2000-01-01', '00:00:00', '23:59:59'); 
        SET @Counter = @Counter + 1;
	END;
	SET @Counter = 1;
	WHILE @Counter <= 1000
	BEGIN
        INSERT INTO EventStaff(eventId, staffCNP)
		VALUES (1, 111122223); 
        SET @Counter = @Counter + 1;
	END;

	
	SET @StartTime = GETDATE();
	SET @Counter = 1;
	WHILE @Counter <= 1000
	BEGIN
        DELETE FROM Bands where bandId=(SELECT TOP 1 bandId FROM Bands ORDER BY bandId DESC);
        SET @Counter = @Counter + 1;
	END;
	set @EndTime=getDate();
	insert into TestTables(TestID, TableID, NoOfRows,Position) values(@TestNr, 1, 1000, 1);
	insert into TestRuns(Description, StartAt, EndAt) values ('delete from table Bands', @StartTime, @EndTime);
	SELECT @testRunRowCount = COUNT(*) FROM TestRuns;
	insert into TestRunTables(TestRunID, TableID, StartAt, EndAt) values(@testRunRowCount, 1, @StartTime, @EndTime);


	SET @StartTime = GETDATE();
	SET @Counter = 1;
	WHILE @Counter <= 1000
	BEGIN
        DELETE FROM Concert where concertId=(SELECT TOP 1 concertId FROM Concert ORDER BY concertId DESC);
        SET @Counter = @Counter + 1;
	END;
	set @EndTime=getDate();
	insert into TestTables(TestID, TableID, NoOfRows,Position) values(@TestNr, 2, 10000, 1);
	insert into TestRuns(Description, StartAt, EndAt) values ('delete from table Concert', @StartTime, @EndTime);
	SELECT @testRunRowCount = COUNT(*) FROM TestRuns;
	insert into TestRunTables(TestRunID, TableID, StartAt, EndAt) values(@testRunRowCount, 2, @StartTime, @EndTime);

	SET @StartTime = GETDATE();
	SET @Counter = 1;
	WHILE @Counter <= 1000
	BEGIN
        delete from EventStaff where id=(select top 1 id from EventStaff order by id DESC);
        SET @Counter = @Counter + 1;
	END;
	set @EndTime=getDate();
	insert into TestTables(TestID, TableID, NoOfRows,Position) values(@TestNr, 3, 10000, 1);
	insert into TestRuns(Description, StartAt, EndAt) values ('delete from table EventStaff', @StartTime, @EndTime);
	SELECT @testRunRowCount = COUNT(*) FROM TestRuns;
	insert into TestRunTables(TestRunID, TableID, StartAt, EndAt) values(@testRunRowCount, 3, @StartTime, @EndTime);

end;
go

exec TestView;
exec TestInsert;
exec TestDelete;