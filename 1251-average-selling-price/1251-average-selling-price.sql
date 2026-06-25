# Write your MySQL query statement below

select e1.product_id, 
round(ifnull(sum(e1.price*e2.units)/sum(e2.units),0),2) as average_price
from Prices e1
left join UnitsSold e2
on e1.product_id= e2.product_id
and e2.purchase_date>=e1.start_date and e2.purchase_date<=e1.end_date
group by e1.product_id;
