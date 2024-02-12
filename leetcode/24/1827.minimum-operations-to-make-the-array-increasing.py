#
# @lc app=leetcode id=1827 lang=python3
#
# [1827] Minimum Operations to Make the Array Increasing
#

# @lc code=start
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        l,r = 0,1
        count = 0
        if len(nums)==1:
            return l
        while r<len(nums):
            if nums[l]>=nums[r]:
                delta = nums[l]-nums[r]+1
                nums[r] = nums[r]+delta
                count+=delta
            l+=1
            r+=1
        return count
# @lc code=end

