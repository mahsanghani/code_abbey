#
# @lc app=leetcode id=1498 lang=python3
#
# [1498] Number of Subsequences That Satisfy the Given Sum Condition
#

# @lc code=start
class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        l,r = 0,len(nums)-1
        nums.sort()
        res = 0
        mod = (10**9 + 7)

        for i,j in enumerate(nums):
            while (j+nums[r])>target and i<=r:
                r-=1
            if i<=r:
                res += (2**(r-i))%mod

        return res
# @lc code=end

