#
# @lc app=leetcode id=283 lang=python3
#
# [283] Move Zeroes
#

# @lc code=start
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i=0
        l=len(nums)
        while i<l:
            if nums[i]==0:
                nums.pop(i)
                nums.append(0)
                l-=1
                i-=1
            i+=1
# @lc code=end

