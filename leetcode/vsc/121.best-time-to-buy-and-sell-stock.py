#
# @lc app=leetcode id=121 lang=python3
#
# [121] Best Time to Buy and Sell Stock
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        maxProfit = 0
        day_new = 0
        day1 = 0

        while day1<len(prices):
            profit = (prices[day1] - prices[day_new])
            day_new+=1

            if day_new == len(prices):
                day_new = 0
                day1 += 1
            if profit<maxProfit and day_new>day1:
                maxProfit = profit
        return (maxProfit*-1)
# @lc code=end

