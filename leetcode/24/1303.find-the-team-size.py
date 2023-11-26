#
# @lc app=leetcode id=1303 lang=MySQL
#
# [1303] Find the Team Size
#
# @lc code=start
# Write your MySQL query statement below
select employee_id, count(employee_id) over (partition by team_id) as team_size from Employee
# @lc code=end

