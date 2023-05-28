#
# @lc app=leetcode id=714 lang=python3
#
# [714] Best Time to Buy and Sell Stock with Transaction Fee
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        length = len(prices)
        hold, free = -prices[0], 0

        for i in range(1, length):
            temp = hold
            hold = max(hold, free - prices[i])
            free = max(free, temp + prices[i] - fee)

        return free
# @lc code=end

