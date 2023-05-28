#
# @lc app=leetcode id=309 lang=python3
#
# [309] Best Time to Buy and Sell Stock with Cooldown
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = {} # key=(i, buying)

        def dfs(i, buying):
            if i>=len(prices):
                return 0
            elif (i, buying) in dp:
                return dp[(i, buying)]
            
            cool = dfs(i+1, buying)
            if buying:
                buy = dfs(i+1, not buying) - prices[i]
                dp[(i, buying)] = max(buy, cool) # cache
            else:
                sell = dfs(i+2, not buying) + prices[i]
                dp[(i, buying)] = max(sell, cool) # cache
            return dp[(i, buying)]
        
        return dfs(0, True)
# @lc code=end
