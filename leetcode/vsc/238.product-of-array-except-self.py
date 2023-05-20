#
# @lc app=leetcode id=238 lang=python3
#
# [238] Product of Array Except Self
#

# @lc code=start
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        results=[]
        pre,post=1,1
        for num in nums:
            results.append(pre)
            pre*=num
        for i in range(len(nums)-1,-1,-1):
            results[i]*=post
            post*=nums[i]
        return results
# @lc code=end

