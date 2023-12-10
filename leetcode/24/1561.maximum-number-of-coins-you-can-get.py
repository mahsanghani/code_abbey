#
# @lc app=leetcode id=1561 lang=python3
#
# [1561] Maximum Number of Coins You Can Get
#

# @lc code=start
from collections import deque
class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        res=0
        q=deque(sorted(piles))

        while q:
            q.pop()
            res+=q.pop()
            q.popleft()

        return res
# @lc code=end