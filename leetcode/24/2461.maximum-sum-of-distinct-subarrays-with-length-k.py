#
# @lc app=leetcode id=2461 lang=python3
#
# [2461] Maximum Sum of Distinct Subarrays With Length K
#

# @lc code=start
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        results = 0
        for i in range(len(nums)-k+1):
            if len(set(nums[i:i+k]))==len(nums[i:i+k]):
                results = max(results, sum(nums[i:i+k]))
        return results
# @lc code=end

