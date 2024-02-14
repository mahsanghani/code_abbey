#
# @lc app=leetcode id=1823 lang=python3
#
# [1823] Find the Winner of the Circular Game
#

# @lc code=start
class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        if n==1:
            return 1
        return (k+self.findTheWinner(n-1,k)-1)%n+1
# @lc code=end

