# Write your MySQL query statement below

select emp.name,bo.bonus
from Employee emp
left join Bonus bo
on emp.empId = bo.empId
where bo.bonus <1000 or bo.bonus is null;
