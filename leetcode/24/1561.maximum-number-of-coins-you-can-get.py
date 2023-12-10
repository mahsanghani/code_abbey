#
# @lc app=leetcode id=1561 lang=python3
#
# [1561] Maximum Number of Coins You Can Get
#

# @lc code=start
from collections import deque
class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        res = 0
        piles.sort()

        for i in range(len(piles)//3,len(piles),2):
            res+=piles[i]

        return res
# @lc code=end