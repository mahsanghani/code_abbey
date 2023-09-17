#
# @lc app=leetcode id=2369 lang=python3
#
# [2369] Check if There is a Valid Partition For The Array
#

# @lc code=start
class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        memo = {-1: True}

        def prefix(i):
            if i in memo:
                return memo[i]
            res = False

            if i>0 and nums[i]==nums[i-1]:
                res |= prefix(i-2)
            if i>1 and nums[i]==nums[i-1]==nums[i-2]:
                res |= prefix(i-3)
            if i>1 and nums[i]==nums[i-1]+1==nums[i-2]+2:
                res |= prefix(i-3)
            memo[i] = res
            return res
        
        return prefix(n-1)
# @lc code=end

