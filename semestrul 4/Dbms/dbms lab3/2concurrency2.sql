USE Concerts;
GO
DROP TABLE IF EXISTS TransactionLog;
CREATE TABLE TransactionLog (
    TransactionId INT IDENTITY(1,1) PRIMARY KEY,
    ScenarioName VARCHAR(50),
    ActionDescription VARCHAR(100),
    ExecutionTime DATETIME DEFAULT GETDATE(),
    ReadValue VARCHAR(50)
);
GO
SELECT * FROM TransactionLog;
SELECT * FROM Songs;
SELECT * FROM Bands;

-- Dirty Read
USE Concerts;
GO
SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED;
BEGIN TRANSACTION;
DECLARE @ReadValueDirtyRead VARCHAR(50);
SELECT * FROM Bands WHERE bandId=1;
SELECT @ReadValueDirtyRead = bandName FROM Bands WHERE bandId = 1;
INSERT INTO TransactionLog (ScenarioName, ActionDescription, ReadValue) VALUES ('Dirty Read', 'Read Bands data with READ UNCOMMITTED isolation level', @ReadValueDirtyRead);
COMMIT;
GO

-- Solution for Dirty Read
SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
BEGIN TRANSACTION;
DECLARE @ReadValueDirtyReadSolution VARCHAR(50);
SELECT @ReadValueDirtyReadSolution = bandName FROM Bands WHERE bandId = 1;
SELECT * FROM Bands WHERE bandId=1;
INSERT INTO TransactionLog (ScenarioName, ActionDescription, ReadValue) VALUES ('Dirty Read Solution', 'Read Bands data with READ COMMITTED isolation level', @ReadValueDirtyReadSolution);
COMMIT;
GO

-- Non-repeatable Read
USE Concerts;
GO
BEGIN TRANSACTION;
UPDATE Bands SET bandName = 'non_repeatable' WHERE bandId = 1;
DECLARE @ReadValueNonRepeatableRead VARCHAR(50);
SELECT @ReadValueNonRepeatableRead = bandName FROM Bands WHERE bandId = 1;
INSERT INTO TransactionLog (ScenarioName, ActionDescription, ReadValue) VALUES ('Non-Repeatable Read', 'Update Bands data', @ReadValueNonRepeatableRead);
COMMIT;
GO

-- Phantom Read
USE Concerts;
GO
BEGIN TRANSACTION;
INSERT INTO Songs (name, bandId, album, minutes) VALUES ('phantom', 1, 'read', 4);
DECLARE @ReadValuePhantomRead VARCHAR(50);
SELECT @ReadValuePhantomRead = name FROM Songs WHERE bandId = 1 AND name = 'phantom';
INSERT INTO TransactionLog (ScenarioName, ActionDescription, ReadValue) VALUES ('Phantom Read', 'Insert new song data', @ReadValuePhantomRead);
COMMIT;
GO

-- Deadlock
USE Concerts;
GO
BEGIN TRANSACTION;
UPDATE Songs SET name = 'Session 2 Song' WHERE songId = 1;
UPDATE Bands SET bandName = 'Session 2 Band' WHERE bandId = 1;
DECLARE @ReadValueDeadlockBands VARCHAR(50);
DECLARE @ReadValueDeadlockSongs VARCHAR(50);
SELECT @ReadValueDeadlockBands = bandName FROM Bands WHERE bandId = 1;
SELECT @ReadValueDeadlockSongs = name FROM Songs WHERE songId = 1;
INSERT INTO TransactionLog (ScenarioName, ActionDescription, ReadValue) VALUES ('Deadlock - Bands', 'Update Bands data', @ReadValueDeadlockBands);
INSERT INTO TransactionLog (ScenarioName, ActionDescription, ReadValue) VALUES ('Deadlock - Songs', 'Update Songs data', @ReadValueDeadlockSongs);
COMMIT;
GO

-- Optimistic Concurrency
ALTER DATABASE Concerts
SET ALLOW_SNAPSHOT_ISOLATION ON;
GO

ALTER DATABASE Concerts
SET READ_COMMITTED_SNAPSHOT ON;
GO

USE Concerts;
GO
SET TRANSACTION ISOLATION LEVEL SNAPSHOT;
BEGIN TRANSACTION;
DECLARE @CurrentVersion INT;
DECLARE @ReadValueOptimistic VARCHAR(50);
SELECT @CurrentVersion = songId FROM Songs WHERE album = 'XX';
SELECT @ReadValueOptimistic = name FROM Songs WHERE songId = @CurrentVersion;
WAITFOR DELAY '00:00:05';
UPDATE Songs SET name = 'optimistic' WHERE songId = @CurrentVersion;
INSERT INTO TransactionLog (ScenarioName, ActionDescription, ReadValue) VALUES ('Optimistic Concurrency', 'Update Songs data with optimistic concurrency control', @ReadValueOptimistic);
COMMIT;
GO


