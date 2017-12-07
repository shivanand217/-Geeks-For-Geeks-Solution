SET @X := 0;
SET @Y := 0;

SELECT COUNT(*) FROM (SELECT @x := @x+1 as Rank1, house_number as H1 
					  FROM houses ORDER BY H1 ASC)A,
					 (SELECT @y := @y+1 as Rank2, house_number as H2
					  FROM houses ORDER BY H1 ASC)B WHERE H1 < H2 
					 AND H1%2=1 AND H2%2=0 AND Rank1%2=0 AND Rank2%2=1;
