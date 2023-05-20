#
# @lc app=leetcode id=238 lang=python3
#
# [238] Product of Array Except Self
#

# @lc code=start
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res=[]
        for i in range(len(nums)):
            nums1=nums[:i]+nums[i+1:]
            res.append(math.prod(nums1))
        return res
        
# @lc code=end

