# Write your MySQL query statement below

select query_name,
round(avg(p.rating/p.position),2) as quality,
round(
    avg(
        case 
            when  rating<3 then 1
            else 0
        end
    )*100
   ,2) as poor_query_percentage 
from Queries p
group by p.query_name;
