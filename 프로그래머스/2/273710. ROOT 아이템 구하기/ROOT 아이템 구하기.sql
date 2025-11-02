-- 코드를 작성해주세요
select I.item_id as item_id, I.item_name as item_name
from item_info as I
join item_tree as T
on I.item_id = T.item_id
where T.parent_item_id is null
order by item_id