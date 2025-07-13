use Concerts;
go

--dirty read:
USE Concerts;
GO
BEGIN TRANSACTION;
UPDATE Bands SET bandName = 'dirty read' WHERE bandId = 1;
WAITFOR DELAY '00:00:10';  
COMMIT;
GO


--non repeatable read
SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
BEGIN TRANSACTION;
SELECT * FROM Bands WHERE bandId = 1;
WAITFOR DELAY '00:00:10';
SELECT * FROM Bands WHERE bandId = 1;
COMMIT;

--solution:
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;
BEGIN TRANSACTION;
SELECT * FROM Bands WHERE bandId = 1;
WAITFOR DELAY '00:00:10';
SELECT * FROM Bands WHERE bandId = 1;
COMMIT;

--phantom read
SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
BEGIN TRANSACTION;
SELECT * FROM Songs WHERE bandId = 1;
WAITFOR DELAY '00:00:10';
SELECT * FROM Songs WHERE bandId = 1;
COMMIT;

--solution:
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
BEGIN TRANSACTION;
SELECT * FROM Songs WHERE bandId = 1;
WAITFOR DELAY '00:00:10';
SELECT * FROM Songs WHERE bandId = 1;
COMMIT;

--deadlock:
BEGIN TRANSACTION;
UPDATE Bands SET bandName = 'Session 1 Band' WHERE bandId = 1;
WAITFOR DELAY '00:00:10';
UPDATE Songs SET name = 'Session 1 Song' WHERE songId = 1;

--optimistic
SET TRANSACTION ISOLATION LEVEL SNAPSHOT;
BEGIN TRANSACTION;
DECLARE @CurrentVersion INT;
SELECT @CurrentVersion = songId FROM Songs WHERE album = 'XX';
WAITFOR DELAY '00:00:10';
UPDATE Songs SET name='optimistic' WHERE songId = @CurrentVersion;
COMMIT;


------------------------------

CREATE DATABASE Songs_snapshot ON (
    NAME = Songs,
    FILENAME = 'C:\Program Files\Microsoft SQL Server\MSSQL16.MSSQLSERVER\MSSQL\Data\AdventureWorks_data_1800.ss'
    ) AS SNAPSHOT OF Songs;
GO


