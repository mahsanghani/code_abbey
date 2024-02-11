#
# @lc app=leetcode id=2485 lang=python3
#
# [2485] Find the Pivot Integer
#

# @lc code=start
class Solution:
    def pivotInteger(self, n: int) -> int:
        for p in range(1,n+1):
            if sum(range(p+1))==sum(range(p,n+1)):
                return p
        return -1
# @lc code=end

