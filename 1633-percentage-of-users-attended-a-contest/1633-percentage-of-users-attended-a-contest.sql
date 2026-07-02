# Write your MySQL query statement below

select c.contest_id ,
round(count(c.user_id)*100/(select count(*) from users) ,2) as percentage
from Register c
group by c.contest_id
order by percentage desc , contest_id asc ;


