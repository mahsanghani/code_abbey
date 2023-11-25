#
# @lc app=leetcode id=121 lang=python3
#
# [121] Best Time to Buy and Sell Stock
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        p,l,r = 0,0,1

        while r<len(prices):
            p=max(p,prices[r]-prices[l])
            if prices[r]<prices[l]:
                l=r
            r+=1
        
        return p
# @lc code=end

