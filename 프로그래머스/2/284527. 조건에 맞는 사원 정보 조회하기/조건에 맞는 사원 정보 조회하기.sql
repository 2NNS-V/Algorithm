-- 코드를 작성해주세요
select sum(G.score) as score, E.emp_no, E.emp_name, E.position, E.email
from hr_department as D
inner join hr_employees as E on D.dept_id = E.dept_id
inner join hr_grade as G on E.emp_no = G.emp_no
group by emp_no
order by score desc
limit 1