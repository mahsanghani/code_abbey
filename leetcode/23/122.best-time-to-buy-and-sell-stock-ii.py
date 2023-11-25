#
# @lc app=leetcode id=122 lang=python3
#
# [122] Best Time to Buy and Sell Stock II
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        p,l,r=0,0,1
        while r<len(prices):
            if prices[r]>prices[l]:
                p+=(prices[r]-prices[l])
                l=r
            else:
                l+=1
            r+=1
        return p
# @lc code=end

