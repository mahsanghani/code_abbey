#
# @lc app=leetcode id=1350 lang=SQL
#
# [1350] Students With Invalid Departments
#
# @lc code=start
# Write your MySQL query statement below
select s.id, s.name from students as s left join departments d on s.department_id = d.id where d.id is NULL
# @lc code=end

