SELECT T1.MEMBER_NAME, T2.REVIEW_TEXT, DATE_FORMAT(T2.REVIEW_DATE, '%Y-%m-%d') AS REVIEW_DATE
FROM MEMBER_PROFILE T1 JOIN REST_REVIEW T2 ON T1.MEMBER_ID = T2.MEMBER_ID
WHERE T2.MEMBER_ID IN (SELECT MEMBER_ID
                     FROM REST_REVIEW
                     GROUP BY MEMBER_ID
                     HAVING COUNT(*) = (
                        SELECT MAX(CNT)
                        FROM (
                            SELECT COUNT(*) AS CNT
                            FROM REST_REVIEW
                            GROUP BY MEMBER_ID
                        ) X
                     )
                )
ORDER BY T2.REVIEW_DATE ASC, T2.REVIEW_TEXT ASC
