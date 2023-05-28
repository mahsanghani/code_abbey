#
# @lc app=leetcode id=123 lang=python3
#
# [123] Best Time to Buy and Sell Stock III
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        length = len(prices)
        left = prices[0]
        right = prices[-1]
        profit_left = [0] * (length)
        profit_right = [0] * (length+1)

        for l in range(1, length):
            r = length - l - 1

            profit_left[l] = max(profit_left[l-1], prices[l]-left)
            left = min(left, prices[l])

            profit_right[r] = max(profit_right[r+1], right-prices[r])
            right = max(right, prices[r])

        profit = 0

        for i in range(0, length):
            profit = max(profit, profit_left[i] + profit_right[i+1])

        return profit
# @lc code=end