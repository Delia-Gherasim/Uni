USE practic;
GO

SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
GO
BEGIN TRANSACTION;
UPDATE FinancialProducts SET price = 300 WHERE productId = 1;
WAITFOR DELAY '00:00:10'; 
UPDATE Cities SET name = 'bbb' WHERE cityId = 1;
COMMIT;


--solution: use the same order when accessing resources
begin transaction 
update Cities set name='bbb' where cityId=1
waitfor delay '00:00:10';
update FinancialProducts set price=300 where productId=1
commit
