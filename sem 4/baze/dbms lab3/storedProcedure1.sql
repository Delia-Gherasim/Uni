USE Concerts;
GO

DROP TABLE IF EXISTS ErrorLog;

CREATE TABLE ErrorLog (
    ErrorId INT IDENTITY(1,1) PRIMARY KEY,
    ProcedureName VARCHAR(50),
    ErrorMessage NVARCHAR(4000),
    ErrorSeverity INT,
    ErrorState INT,
    ErrorTime DATETIME DEFAULT GETDATE()
);
GO

DROP PROCEDURE IF EXISTS InsertDataEventStaff;
DROP PROCEDURE IF EXISTS InsertDataEventStaff2;
GO

CREATE PROCEDURE InsertDataEventStaff
    @eventName VARCHAR(30),
    @organizer VARCHAR(30),
    @staff INT,
    @staffCnp INT,
    @name VARCHAR(30),
    @surname VARCHAR(30),
    @department VARCHAR(30)
AS
BEGIN
    SET NOCOUNT ON;
    BEGIN TRANSACTION;

    BEGIN TRY
        
        DECLARE @eventId INT;
        INSERT INTO Event (eventName, concertId, locationId, organizer, staff)
        VALUES (@eventName, 2, 4, @organizer, @staff);
        SET @eventId = SCOPE_IDENTITY();

        INSERT INTO Staff (staffCNP, name, surname, department)
        VALUES (@staffCnp, @name, @surname, @department);

        INSERT INTO EventStaff (eventId, staffCNP)
        VALUES (@eventId, @staffCnp);

        COMMIT TRANSACTION;
    END TRY
    BEGIN CATCH
        ROLLBACK TRANSACTION;
        DECLARE @ErrorMessage NVARCHAR(4000);
        DECLARE @ErrorSeverity INT;
        DECLARE @ErrorState INT;

        SELECT 
            @ErrorMessage = ERROR_MESSAGE(),
            @ErrorSeverity = ERROR_SEVERITY(),
            @ErrorState = ERROR_STATE();

        INSERT INTO ErrorLog (ProcedureName, ErrorMessage, ErrorSeverity, ErrorState)
        VALUES (
            'InsertDataEventStaff',
            @ErrorMessage,
            @ErrorSeverity,
            @ErrorState
        );
    END CATCH
END;
GO

CREATE PROCEDURE InsertDataEventStaff2
    @eventName VARCHAR(30),
    @organizer VARCHAR(30),
    @staff INT,
    @staffCnp INT,
    @name VARCHAR(30),
    @surname VARCHAR(30),
    @department VARCHAR(30)
AS
BEGIN
    SET NOCOUNT ON;
    BEGIN TRANSACTION;

    BEGIN TRY
        
        DECLARE @eventId INT;
        INSERT INTO Event (eventName, concertId, locationId, organizer, staff)
        VALUES (@eventName, 2, 4, @organizer, @staff);
        SET @eventId = SCOPE_IDENTITY();
	END TRY
	BEGIN CATCH
		DECLARE @ErrorMessage NVARCHAR(4000);
        DECLARE @ErrorSeverity INT;
        DECLARE @ErrorState INT;

        SELECT 
            @ErrorMessage = ERROR_MESSAGE(),
            @ErrorSeverity = ERROR_SEVERITY(),
            @ErrorState = ERROR_STATE();

        INSERT INTO ErrorLog (ProcedureName, ErrorMessage, ErrorSeverity, ErrorState)
        VALUES (
            'InsertDataEventStaff2',
            @ErrorMessage,
            @ErrorSeverity,
            @ErrorState
        );
	END CATCH

	BEGIN TRY
        INSERT INTO Staff (staffCNP, name, surname, department)
        VALUES (@staffCnp, @name, @surname, @department);
	END TRY
	BEGIN CATCH
        SELECT 
            @ErrorMessage = ERROR_MESSAGE(),
            @ErrorSeverity = ERROR_SEVERITY(),
            @ErrorState = ERROR_STATE();

        INSERT INTO ErrorLog (ProcedureName, ErrorMessage, ErrorSeverity, ErrorState)
        VALUES (
            'InsertDataEventStaff2',
            @ErrorMessage,
            @ErrorSeverity,
            @ErrorState
        );
	END CATCH

	BEGIN TRY
        INSERT INTO EventStaff (eventId, staffCNP)
        VALUES (@eventId, @staffCnp);
	END TRY
	BEGIN CATCH
        SELECT 
            @ErrorMessage = ERROR_MESSAGE(),
            @ErrorSeverity = ERROR_SEVERITY(),
            @ErrorState = ERROR_STATE();

        INSERT INTO ErrorLog (ProcedureName, ErrorMessage, ErrorSeverity, ErrorState)
        VALUES (
            'InsertDataEventStaff2',
            @ErrorMessage,
            @ErrorSeverity,
            @ErrorState
        );
	END CATCH
	COMMIT TRANSACTION;
END;
GO

EXEC InsertDataEventStaff
    @eventName = 'Rock Concert',
    @organizer = 'MusicOrg',
    @staff = 10,
    @staffCnp = 1234567891,
    @name = 'Popescu',
    @surname = 'Pop',
    @department = 'Security';
GO
Select * from EventStaff
EXEC InsertDataEventStaff2
    @eventName = 'Rock Concert',
    @organizer = 'MusicOrg',
    @staff = 10,
    @staffCnp = 1234567891,
    @name = 'Popescu',
    @surname = 'Pop',
    @department = 'Security';
GO

SELECT * FROM ErrorLog;
