#
# @lc app=leetcode id=1498 lang=python3
#
# [1498] Number of Subsequences That Satisfy the Given Sum Condition
#

# @lc code=start
class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        l,r=0,len(nums)-1
        res,mod=0,(10**9+7)

        while l<=r:
            if nums[l]+nums[r]>target:
                r-=1
            else:
                res+=1 << (r-l)
                l+=1
        return res%mod
# @lc code=end

