WITH cte AS (
    SELECT requester_id AS id, COUNT(requester_id) AS rc 
    FROM RequestAccepted 
    GROUP BY requester_id
),
abc AS (
    SELECT accepter_id AS id, COUNT(accepter_id) AS ac 
    FROM RequestAccepted 
    GROUP BY accepter_id
)
SELECT id, num
FROM (
    SELECT cte.id AS id, (IFNULL(cte.rc, 0) + IFNULL(abc.ac, 0)) AS num
    FROM cte
    LEFT JOIN abc ON cte.id = abc.id

    UNION

    SELECT abc.id AS id, (IFNULL(cte.rc, 0) + IFNULL(abc.ac, 0)) AS num
    FROM cte
    RIGHT JOIN abc ON cte.id = abc.id
) AS der
ORDER BY num DESC
LIMIT 1;