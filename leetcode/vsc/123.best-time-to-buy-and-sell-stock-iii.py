#
# @lc app=leetcode id=123 lang=python3
#
# [123] Best Time to Buy and Sell Stock III
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit1 = 0
        profit2 = 0
        cost1 = float("inf")
        cost2 = float("inf")

        for price in prices:
            cost1 = min(cost1,price)
            profit1 = max(profit1, price-cost1)
            cost2 = min(cost2,price-profit1)
            profit2 = max(profit2, price-cost2)

        return profit2
# @lc code=end