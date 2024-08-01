# Write your MySQL query statement below
with cte AS
(SELECT A.player_id, MIN(A.event_date) AS fl
FROM Activity A GROUP BY A.player_id),
cls AS (
    SELECT COUNT(A.player_id) AS nl
    FROM cte c JOIN Activity A
    ON c.player_id = A.player_id
    AND c.fl = DATE_SUB(A.event_date, INTERVAL 1 DAY)
)

SELECT 
ROUND( (SELECT c.nl FROM cls c)
    / (SELECT COUNT(F.player_id) FROM cte F), 2) AS fraction;