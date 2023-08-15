#
# @lc app=leetcode id=209 lang=python3
#
# [209] Minimum Size Subarray Sum
#

# @lc code=start
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l,r,tot=0,0,0
        results=float("inf")

        for r in range(len(nums)):
            tot+=nums[r]
            while tot>=target:
                results = min(results,r-l+1)
                tot -= nums[l]
                l += 1

        return 0 if results == float("inf") else results
# @lc code=end

