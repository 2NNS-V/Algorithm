-- 코드를 작성해주세요
select count(*) as fish_count, N.fish_name
from fish_info as I
join fish_name_info as N
on I.fish_type = N.fish_type 
group by N.fish_name
order by fish_count desc