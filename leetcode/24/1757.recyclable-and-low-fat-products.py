#
# @lc app=leetcode id=1757 lang=MySQL
#
# [1757] Recyclable and Low Fat Products
#

# @lc code=start
# Write your MySQL query statement below
SELECT product_id FROM Products WHERE recyclable='Y' AND low_fats='Y';
# @lc code=end

