SELECT s.product_id, gs.year AS first_year, s.quantity, s.price
FROM Sales s, (
SELECT product_id, MIN(year) as year
FROM Sales
GROUP BY product_id) AS gs
WHERE s.product_id = gs.product_id AND s.year = gs.year;
