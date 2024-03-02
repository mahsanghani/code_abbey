#
# @lc app=leetcode id=75 lang=python3
#
# [75] Sort Colors
#
# @lc code=start
from collections import Counter
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i,l,r = 0,0,len(nums)-1

        def swap(j,k):
            temp = nums[j]
            nums[j] = nums[k]
            nums[k] = temp

        while i<=r:
            if nums[i]==0:
                swap(l,i)
                l+=1
            elif nums[i]==2:
                swap(i,r)
                r-=1
                i-=1
            i+=1
        
# @lc code=end

