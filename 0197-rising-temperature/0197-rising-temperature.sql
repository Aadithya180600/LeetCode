# Write your MySQL query statement below
SELECT w.id as Id FROM Weather w
JOIN Weather v
ON v.recordDate = w.recordDate - INTERVAL 1 DAY 
WHERE w.temperature > v.temperature;