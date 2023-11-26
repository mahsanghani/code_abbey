#
# @lc app=leetcode id=1571 lang=MySQL
#
# [1571] Warehouse Manager
#
# @lc code=start
# Write your MySQL query statement below
select
    w.name as warehouse_name,
    sum(p.Width * p.Length * p.Height * w.units) as volume
from Warehouse w
inner join Products p
on w.product_id = p.product_id
group by w.name;
# @lc code=end

