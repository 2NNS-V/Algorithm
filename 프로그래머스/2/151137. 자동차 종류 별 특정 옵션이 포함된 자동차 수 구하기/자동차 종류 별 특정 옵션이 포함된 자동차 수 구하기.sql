SELECT car_type,
       COUNT(
         CASE 
           WHEN options LIKE '%통풍시트%' 
             OR options LIKE '%열선시트%' 
             OR options LIKE '%가죽시트%' 
           THEN 1 
         END
       ) AS cars
FROM car_rental_company_car
GROUP BY car_type
ORDER BY car_type;
