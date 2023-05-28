#
# @lc app=leetcode id=714 lang=python3
#
# [714] Best Time to Buy and Sell Stock with Transaction Fee
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        hold, free = [0]*len(prices), [0]*len(prices)
        hold[0] = -prices[0]
        
        for i in range(1, len(prices)):
            hold[i] = max(hold[i-1], free[i-1] - prices[i])
            free[i] = max(free[i-1], hold[i-1] + prices[i] - fee)

        return free[-1]
# @lc code=end

