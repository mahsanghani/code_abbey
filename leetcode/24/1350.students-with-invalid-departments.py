#
# @lc app=leetcode id=1350 lang=SQL
#
# [1350] Students With Invalid Departments
#
# @lc code=start
# Write your MySQL query statement below
select id, name from students where department_id not in (select id from departments)
# @lc code=end

