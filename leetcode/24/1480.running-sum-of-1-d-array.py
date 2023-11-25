#
# @lc app=leetcode id=1480 lang=python3
#
# [1480] Running Sum of 1d Array
#

# @lc code=start
class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        results = nums[:1]
        for i in range(1,len(nums)):
            results.append(results[-1]+nums[i])
        return results
# @lc code=end

