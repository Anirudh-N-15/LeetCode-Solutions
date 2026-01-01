# Write your MySQL query statement below
UPDATE Salary 
SET sex = ( case when sex like 'm' then 'f' 
                 when sex like 'f' then 'm' 
                end)