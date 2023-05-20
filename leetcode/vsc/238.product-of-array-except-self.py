#
# @lc app=leetcode id=238 lang=python3
#
# [238] Product of Array Except Self
#

# @lc code=start
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res=[]

        pre=1
        for num in nums:
            res.append(pre)
            pre*=num
        
        post=1
        for i in range(len(nums)-1,-1,-1):
            res[i]*=post
            post*=nums[i]
        
        return res
# @lc code=end

