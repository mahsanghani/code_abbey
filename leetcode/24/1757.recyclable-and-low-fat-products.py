#
# @lc app=leetcode id=1757 lang=python3
#
# [1757] Recyclable and Low Fat Products
#

# @lc code=start
# Write your MySQL query statement below
select product_id from Products where recyclable="Y" and low_fats="Y"
# @lc code=end

