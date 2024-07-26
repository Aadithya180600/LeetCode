# Write your MySQL query statement below
-- SELECT s.user_id,
-- (SELECT COUNT(action) FROM Confirmations where action = 'confirmed') AS con
-- FROM Signups s
-- LEFT JOIN Confirmations c
-- ON c.user_id = s.user_id
-- GROUP BY s.user_id, c.action;

-- SELECT P.user_id,

-- (CASE
--     WHEN P.cou = '0' THEN 0.00
--     ELSE ROUND(((P.cou*1.0)/(P.cou+T.rej)), 2)
-- END
-- ) AS confirmation_rate

-- FROM
-- (SELECT s.user_id, COUNT(c.action) AS cou
-- FROM Signups s
-- LEFT JOIN Confirmations c
-- ON c.user_id = s.user_id AND c.action = 'confirmed'
-- GROUP BY s.user_id) AS P
-- JOIN
-- (SELECT s.user_id, COUNT(c.action) AS rej
-- FROM Signups s
-- LEFT JOIN Confirmations c
-- ON c.user_id = s.user_id AND c.action = 'timeout'
-- GROUP BY s.user_id) AS T

-- ON P.user_id = T.user_id;

SELECT s.user_id,
ROUND(AVG(if(c.action = 'confirmed', 1, 0)), 2) AS confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c
ON c.user_id = s.user_id
group by s.user_id;
