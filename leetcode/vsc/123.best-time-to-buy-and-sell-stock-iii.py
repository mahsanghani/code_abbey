#
# @lc app=leetcode id=123 lang=python3
#
# [123] Best Time to Buy and Sell Stock III
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        left = prices[0]
        right = prices[-1]

        length = len(prices)
        pl = [0]*length
        pr = [0]*(length+1)

        for l in range(1,length):
            pl[l] = max(pl[l-1], prices[l]-left)
            left = min(left,prices[l])

            r = length - l - 1

            pr[r] = max(pr[r+1], right-prices[r])
            right = max(right, prices[r])

        profit = 0

        for i in range(0, length):
            profit = max(profit, pl[i]+pr[i+1])
        
        return profit
# @lc code=end