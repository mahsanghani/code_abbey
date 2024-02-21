#
# @lc app=leetcode id=1304 lang=python3
#
# [1304] Find N Unique Integers Sum up to Zero
#

# @lc code=start
class Solution:
    def sumZero(self, n: int) -> List[int]:
        v=[0]*n
        for i in range(n):
            v[i]=2*i-n+1
        return v
# @lc code=end

