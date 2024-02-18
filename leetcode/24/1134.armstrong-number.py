#
# @lc app=leetcode id=1134 lang=python3
#
# [1134] Armstrong Number
#

# @lc code=start
class Solution:
    def isArmstrong(self, n: int) -> bool:
        total = 0
        power = len(str(n))
        for c in str(n):
            total+=int(c)**power
        return n==total
# @lc code=end

