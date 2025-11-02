-- 코드를 작성해주세요
select count(*) as fish_count 
from fish_info as I
left join fish_name_info as N
on N.fish_type = I.fish_type
where N.fish_name = 'BASS' or N.fish_name = 'SNAPPER'
