#
# @lc app=leetcode id=1421 lang=MySQL
#
# [1421] NPV Queries
#
# @lc code=start
# Write your MySQL query statement below
select q.id, q.year, coalesce(n.npv, 0) as npv
from queries q left join NPV n on q.id = n.id
and q.year = n.year
# @lc code=end

