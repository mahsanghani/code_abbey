#
# @lc app=leetcode id=123 lang=python3
#
# [123] Best Time to Buy and Sell Stock III
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        p1,p2,c1,c2 = 0,0,float("inf"), float("inf")
        
        for p in prices:
            c1 = min(c1,p)
            p1 = max(p1,p-c1)

            c2 = min(c2,p-p1)
            p2 = max(p2,p-c2)

        return p2
# @lc code=end