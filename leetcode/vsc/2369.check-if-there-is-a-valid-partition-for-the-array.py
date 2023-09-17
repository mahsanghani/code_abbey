#
# @lc app=leetcode id=2369 lang=python3
#
# [2369] Check if There is a Valid Partition For The Array
#

# @lc code=start
class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [True]+[False]*n

        for i in range(n):
            dp_idx = i+1
            if i>0 and nums[i]==nums[i-1]:
                dp[dp_idx] |= dp[dp_idx-2]
            if i>1 and nums[i]==nums[i-1]==nums[i-2]:
                dp[dp_idx] |= dp[dp_idx-3]
            if i>1 and nums[i]==nums[i-1]+1==nums[i-2]+2:
                dp[dp_idx] |= dp[dp_idx-3]

        return dp[n]
# @lc code=end

