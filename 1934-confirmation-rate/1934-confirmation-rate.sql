# Write your MySQL query statement below

select  s.user_id,
round(avg(case
    when c.action='timeout' then 0
    when c.action= 'confirmed' then 1
    when c.action is null  then 0
    end 
    ),2) as confirmation_rate
from Signups s
left join Confirmations c
on c.user_id = s.user_id
group by user_id;