# Write your MySQL query statement below
select customer_id, COUNT(*) AS count_no_trans
from Visits LEFT OUTER JOIN Transactions ON Visits.visit_id = Transactions.visit_id
WHERE transaction_id is null
GROUP BY customer_id