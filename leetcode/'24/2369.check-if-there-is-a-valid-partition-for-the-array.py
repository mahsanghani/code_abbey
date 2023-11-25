#
# @lc app=leetcode id=2369 lang=python3
#
# [2369] Check if There is a Valid Partition For The Array
#

# @lc code=start
class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [True]+[False]*2

        for i in range(n):
            dp_idx = i+1
            res = False
            if i>0 and nums[i]==nums[i-1]:
                res |= dp[(dp_idx-2)%3]
            if i>1 and nums[i]==nums[i-1]==nums[i-2]:
                res |= dp[(dp_idx-3)%3]
            if i>1 and nums[i]==nums[i-1]+1==nums[i-2]+2:
                res |= dp[(dp_idx-3)%3]
            dp[dp_idx%3] = res
        return dp[n%3]
# @lc code=end

