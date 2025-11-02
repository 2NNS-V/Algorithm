-- 코드를 입력하세요
select animal_type, IFNULL(name, 'No name') as NAME, sex_upon_intake
from animal_ins
order by animal_id
