#
# @lc app=leetcode id=1795 lang=MySQL
#
# [1795] Rearrange Products Table
#

# @lc code=start
# Write your MySQL query statement below
select * from (
select product_id,  "store1" as store,  store1 as "price" from Products
UNION
select product_id,  "store2" as store,  store2 as "price" from Products
UNION
select product_id,  "store3" as store,  store3 as "price" from Products) tmp
where price is not null
# @lc code=end

