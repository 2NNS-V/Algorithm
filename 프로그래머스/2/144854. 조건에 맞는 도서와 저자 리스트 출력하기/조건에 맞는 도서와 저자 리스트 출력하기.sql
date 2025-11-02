-- 코드를 입력하세요
select B.book_id, A.author_name, date_format(B.published_date, '%Y-%m-%d') as published_date
from book as B, author as A
where A.author_id = B.author_id and B.category = '경제'
order by B.published_date