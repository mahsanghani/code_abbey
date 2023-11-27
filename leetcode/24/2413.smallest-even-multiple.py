#
# @lc app=leetcode id=2413 lang=python3
#
# [2413] Smallest Even Multiple
#

# @lc code=start
class Solution:
    def smallestEvenMultiple(self, n: int) -> int:
        for i in range(n,301):
            if i%2==0 and i%n==0:
                return i
        return 0
# @lc code=end

