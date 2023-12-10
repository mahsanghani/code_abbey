#
# @lc app=leetcode id=1561 lang=python3
#
# [1561] Maximum Number of Coins You Can Get
#

# @lc code=start
class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        results = 0
        piles = sorted(piles,reverse=True)
        for i in range(0,len(piles),3):
            results+=piles[i+1]
        return results
# @lc code=end

