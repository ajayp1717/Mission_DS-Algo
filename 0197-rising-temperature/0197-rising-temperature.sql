# Write your MySQL query statement below
select e1.id as Id
from weather e1 join
weather e2 on DATEDIFF(e1.recordDate ,e2.recordDate)=1 and e1.temperature > e2.temperature
