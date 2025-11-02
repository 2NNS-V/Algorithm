-- 코드를 입력하세요
select P.product_code, sum(P.price * S.sales_amount) as sales
from product as P, offline_sale as S
where P.product_id = S.product_id
group by P.product_code 
order by sales desc, P.product_code