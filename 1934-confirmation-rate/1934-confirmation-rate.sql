WITH confirmation_rate AS (
    SELECT user_id,
           ROUND(SUM(CASE WHEN action = 'confirmed' THEN 1 ELSE 0 END) * 1.0 / COUNT(*), 2) AS confirmation_rate
    FROM Confirmations
    GROUP BY user_id
)

SELECT s.user_id,
       COALESCE(c.confirmation_rate, 0) AS confirmation_rate
FROM Signups s
LEFT JOIN confirmation_rate c
ON s.user_id = c.user_id;