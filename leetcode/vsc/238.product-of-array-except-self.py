#
# @lc app=leetcode id=238 lang=python3
#
# [238] Product of Array Except Self
#

# @lc code=start
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        results=[]
        for i in range(len(nums)):
            nums2=nums[:i]+nums[i+1:]
            results.append(math.prod(nums2))
        return results
# @lc code=end

