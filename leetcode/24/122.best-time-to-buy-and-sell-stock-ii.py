#
# @lc app=leetcode id=122 lang=python3
#
# [122] Best Time to Buy and Sell Stock II
#
# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit,left,right = 0,0,1
        while right<len(prices):
            if prices[right]>prices[left]:
                profit+=prices[right]-prices[left]
                left=right
            else:
                left+=1
            right+=1
        return profit
# @lc code=end

