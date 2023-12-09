#
# @lc app=leetcode id=1393 lang=MySQL
#
# [1393] Capital Gain/Loss
#

# @lc code=start
# Write your MySQL query statement below
SELECT stock_name,
SUM(
Case
	When operation='Buy' then -price
	When operation='Sell' then price
End) 
As capital_gain_loss
FROM Stocks
Group By stock_name
# @lc code=end

