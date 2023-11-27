#
# @lc app=leetcode id=2413 lang=python3
#
# [2413] Allow One Function Call
#

# @lc code=start
class Solution:
    def smallestEvenMultiple(self, n: int) -> int:
        for i in range(n,301):
            if i%2==0 and i%n==0:
                return i
# @lc code=end

