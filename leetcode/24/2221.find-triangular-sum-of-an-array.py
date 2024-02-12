#
# @lc app=leetcode id=2221 lang=python3
#
# [2221] Find Triangular Sum of an Array
#

# @lc code=start
class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        while len(nums)>1:
            l,r = 0,1
            while r<len(nums):
                nums[l] = (nums[l]+nums[r])%10
                l+=1
                r+=1
            nums = nums[:-1]
        return nums[0]

# @lc code=end

