# Write your MySQL query statement below
SELECT r.manager_id AS employee_id, e.name, r.reports_count, ROUND(r.avaerage_age, 0) AS average_age
FROM Employees e,(
SELECT reports_to AS manager_id, COUNT(employee_id) AS reports_count, AVG(age) AS avaerage_age
FROM Employees
GROUP BY reports_to
HAVING reports_to IS NOT NULL) AS r
WHERE r.manager_id = e.employee_id
ORDER BY r.manager_id;