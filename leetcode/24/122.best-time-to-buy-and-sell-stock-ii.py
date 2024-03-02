#
# @lc app=leetcode id=122 lang=python3
#
# [122] Best Time to Buy and Sell Stock II
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mini,maxi,diff,l,r = 0,0,0,0,len(prices)-1

        while l<r:
            if prices[r]-prices[l]>diff:
                diff=prices[r]-prices[l]
            if prices[l+1]<mini:
                l+=1
            if prices[r-1]>maxi:
                r-=1

        return diff
# @lc code=end

