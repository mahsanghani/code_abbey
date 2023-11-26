#
# @lc app=leetcode id=1741 lang=python3
#
# [1741] Find Total Time Spent by Each Employee
#
# @lc code=start
# Write your MySQL query statement below
select event_day as "day", emp_id, sum(out_time - in_time) as total_time
from employees
group by event_day, emp_id
# @lc code=end

