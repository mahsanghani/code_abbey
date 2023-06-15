#
# @lc app=leetcode id=2348 lang=python3
#
# [2348] Number of Zero-Filled Subarrays
#

# @lc code=start
class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        results, counts = 0, 0
        for i in range(len(nums)):
            if nums[i]==0:
                counts+=1
                results+=counts
            else:
                counts = 0
        return results
# @lc code=end

