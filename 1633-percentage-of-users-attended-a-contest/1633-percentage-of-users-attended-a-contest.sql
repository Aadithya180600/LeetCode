# Write your MySQL query statement below
SELECT 
r.contest_id, ROUND(COUNT(DISTINCT(r.user_id))/COUNT(DISTINCT(u.user_id)) * 100, 2) AS percentage
-- ROUND((COUNT(r.contest_id)/COUNT(u.user_id)) * 100, 2) AS percentage
FROM Users AS u ,
Register AS r
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id ASC;