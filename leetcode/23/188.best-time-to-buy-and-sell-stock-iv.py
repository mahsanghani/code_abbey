#
# @lc app=leetcode id=188 lang=python3
#
# [188] Best Time to Buy and Sell Stock IV
#

# @lc code=start
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        length = len(prices)

        if k==0:
            return 0
        if not prices:
            return 0
        
        if 2*k>length:
            result=0
            for i,j in zip(prices[1:], prices[:-1]):
                result += max(0,i-j)
            return result
        
        dp = [[[float("-inf")]*2 for _ in range(k+1)] for _ in range(length)]

        dp[0][0][0] = 0
        dp[0][1][1] = -prices[0]

        for i in range(1,length):
            for j in range(k+1):
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i])
                if j>0:
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i])
        
        result = max(dp[length-1][j][0] for j in range(k+1))
        return result

# @lc code=end

