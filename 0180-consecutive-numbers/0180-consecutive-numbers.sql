SELECT DISTINCT l1.num AS ConsecutiveNums FROM Logs l1
JOIN
(
    SELECT l.id AS id, l.num as num1, ll.num as num2 FROM Logs l
    JOIN Logs ll
    WHERE ll.id = l.id + 1
) AS l2
WHERE l2.id = l1.id + 1
AND l1.num = l2.num1 and l2.num1 = l2.num2;