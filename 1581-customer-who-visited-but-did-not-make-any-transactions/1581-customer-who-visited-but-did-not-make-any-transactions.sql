# Write your MySQL query statement below

select e1.customer_id , 
count(*) as count_no_trans
From Visits e1 
left join  Transactions e2
on e1.visit_id=e2.visit_id
where e2.transaction_id is NULL
group by e1.customer_id;