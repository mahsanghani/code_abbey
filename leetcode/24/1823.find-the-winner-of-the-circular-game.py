#
# @lc app=leetcode id=1823 lang=python3
#
# [1823] Find the Winner of the Circular Game
#

# @lc code=start
class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        p=1
        for i in range(1,n):
            p=(k+p-1)%(i+1)+1
        return p
# @lc code=end

