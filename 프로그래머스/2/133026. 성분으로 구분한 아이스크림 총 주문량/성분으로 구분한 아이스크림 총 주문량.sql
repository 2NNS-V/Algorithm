-- 코드를 입력하세요
select I.ingredient_type, sum(H.total_order) as total_order
from first_half as H
inner join icecream_info as I
on H.flavor = I.flavor
group by I.ingredient_type
order by total_order