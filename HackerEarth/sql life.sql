SET @ans = (SELECT MAX(tmp) FROM (SELECT AVG(SQL_Quotient) AS tmp FROM Students
            GROUP BY Group_ID) AS xx);

SELECT ROUND(@ans,2);