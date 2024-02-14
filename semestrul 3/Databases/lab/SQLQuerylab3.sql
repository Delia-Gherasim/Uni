drop procedure alterSongsTable
drop procedure revertAlterSongsTable
drop procedure removeColumn
drop procedure addColumn
drop procedure addDefaultConstrait
drop procedure removeDefaultConstraint
drop procedure addCandidateKey
drop procedure removeCandidateKey
drop procedure addprimaryKey
drop procedure removePrimaryKey
drop procedure addForeignKey
drop procedure removeForeignKey
drop procedure createTable
drop procedure dropTable
drop procedure ExecuteToVersion

go
create procedure alterSongsTable 
as
begin
    alter table Songs
    alter column minutes float;
	DECLARE @RowCount INT;
	SELECT @RowCount = COUNT(*) FROM SaveVersion;
	insert into SaveVersion(number, performedProcedure, reversalProcedure) values
	(@RowCount,'alterSongsTable', 'revertAlterSongsTable');
end;
go

create procedure revertAlterSongsTable
as
begin
    alter table Songs
    alter column minutes int;
	DECLARE @RowCount INT;
	SELECT @RowCount = COUNT(*) FROM SaveVersion;
	insert into SaveVersion(number, performedProcedure, reversalProcedure) values
	(@RowCount,'revertAlterSongsTable', 'alterSongsTable');
end;
go

create procedure addColumn
as
begin
	alter table Staff
	add nickname varchar(30);
	DECLARE @RowCount INT;
	SELECT @RowCount = COUNT(*) FROM SaveVersion;
	insert into SaveVersion(number, performedProcedure, reversalProcedure) values
	(@RowCount,'addColumn', 'removeColumn');
end;
go

create procedure removeColumn
as
begin
	alter table Staff
	drop column nickname;
	DECLARE @RowCount INT;
	SELECT @RowCount = COUNT(*) FROM SaveVersion;
	insert into SaveVersion(number, performedProcedure, reversalProcedure) values
	(@RowCount,'removeColumn','addColumn');
end;
go

create procedure addDefaultConstrait
as
begin
	alter table Effects
	add constraint nume DEFAULT '0' for lasers;
	DECLARE @RowCount INT;
	SELECT @RowCount = COUNT(*) FROM SaveVersion;
	insert into SaveVersion(number, performedProcedure, reversalProcedure) values
	(@RowCount,'addDefaultConstraint', 'removeDefaultConstraint');
end; 
go

create procedure removeDefaultConstraint
as
begin
	alter table Effects
	drop constraint nume;
	DECLARE @RowCount INT;
	SELECT @RowCount = COUNT(*) FROM SaveVersion;
	insert into SaveVersion(number, performedProcedure, reversalProcedure) values
	(@RowCount,'removeDefaultConstraint','addDefaultConstrait');
end;
go

create procedure addprimaryKey
as
begin
	alter table Effects
	add EffectsId int not null;
	alter table Effects
	add constraint pk primary key(EffectsId);
	DECLARE @RowCount INT;
	SELECT @RowCount = COUNT(*) FROM SaveVersion;
	insert into SaveVersion(number, performedProcedure, reversalProcedure) values
	(@RowCount,'addprimaryKey', 'removePrimaryKey');
end;
go

create procedure removePrimaryKey
as
begin
    if exists (select 1 from sys.columns where object_id = object_id('Effects') and name = 'EffectsId')
    begin
		alter table Effects
		drop constraint pk;
        alter table Effects
        drop column EffectsId;
		DECLARE @RowCount INT;
		SELECT @RowCount = COUNT(*) FROM SaveVersion;
		insert into SaveVersion(number, performedProcedure, reversalProcedure) values
		(@RowCount,'removePrimaryKey', 'addprimaryKey');
    end
end;
go

create procedure addCandidateKey
as
begin
	alter table Songs
	add constraint candidateKey unique(songId, bandId);
	DECLARE @RowCount INT;
	SELECT @RowCount = COUNT(*) FROM SaveVersion;
	insert into SaveVersion(number, performedProcedure, reversalProcedure) values
	(@RowCount,'addCandidateKey', 'removeCandidateKey');
end;
go

create procedure removeCandidateKey
as
begin
	alter table Songs
	drop constraint candidateKey;
	DECLARE @RowCount INT;
	SELECT @RowCount = COUNT(*) FROM SaveVersion;
	insert into SaveVersion(number, performedProcedure, reversalProcedure) values
	(@RowCount,'removeCandidateKey','addCandidateKey');
end;
go

create procedure addForeignKey
as
begin
	alter table Locations
	add staffId int;
    alter table Locations
    add constraint FK_Location_Staff foreign key (staffId) references Staff(staffCNP);
	DECLARE @RowCount INT;
	SELECT @RowCount = COUNT(*) FROM SaveVersion;
	insert into SaveVersion(number, performedProcedure, reversalProcedure) values
	(@RowCount,'addForeignKey', 'removeForeignKey');
end;
go


create procedure removeForeignKey
as
begin
    if exists (select 1 from sys.foreign_keys where name = 'FK_Location_Staff')
    begin
        alter table Locations
        drop constraint FK_Location_Staff;
		DECLARE @RowCount INT;
		SELECT @RowCount = COUNT(*) FROM SaveVersion;
		insert into SaveVersion(number, performedProcedure, reversalProcedure) values
		(@RowCount,'removeForeignKey', 'addForeignKey');
    end
end;
go


create procedure createTable
as
begin
	--drop table if exists toBeDeleted;
	create table toBeDeleted(
		column1 int,
		column2 varchar(30),
		column3 int not null
	);
	DECLARE @RowCount INT;
	SELECT @RowCount = COUNT(*) FROM SaveVersion;
	insert into SaveVersion(number, performedProcedure, reversalProcedure) values
	(@RowCount,'createTable', 'dropTable');
end;
go

create procedure dropTable
as
	begin
	drop table if exists toBeDeleted;
	DECLARE @RowCount INT;
	SELECT @RowCount = COUNT(*) FROM SaveVersion;
	insert into SaveVersion(number, performedProcedure, reversalProcedure) values
	(@RowCount,'dropTable', 'createTable');
end;
go

create procedure ExecuteToVersion
    @targetVersion int
as
begin
    declare @currentVersion int;
    select @currentVersion = max(number) from SaveVersion;

    while @currentVersion > @targetVersion
    begin
        declare @performedProcedure nvarchar(max);
        declare @reversalProcedure nvarchar(max);
        
        select top 1 
            @performedProcedure = performedProcedure,
            @reversalProcedure = reversalProcedure
        from SaveVersion
        where number = @currentVersion + 1;
		exec sp_executesql @reversalProcedure;

        set @currentVersion = @currentVersion - 1;
    end
	DECLARE @RowCount INT;
	SELECT @RowCount = COUNT(*) FROM SaveVersion;
	insert into SaveVersion(number, performedProcedure, reversalProcedure) values
	(@RowCount,'ExecuteToVersion', '');
end;
go

use Concerts
exec alterSongsTable;
exec revertAlterSongsTable;
exec addColumn;
exec removeColumn;
exec addDefaultConstrait;
exec removeDefaultConstraint;
exec addprimaryKey;
exec removePrimaryKey;
exec addCandidateKey;
exec removeCandidateKey;
exec addForeignKey;
exec removeForeignKey;
exec createTable;
exec dropTable;
exec ExecuteToVersion @targetVersion = 3;

