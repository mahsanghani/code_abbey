#
# @lc app=leetcode id=912 lang=python3
#
# [912] Sort an Array
#
# @lc code=start
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        counts = {}
        minval,maxval = min(nums),max(nums)
        for val in nums:
            counts[val] = counts.get(val,0)+1
        index = 0

        for val in range(minval,maxval+1,1):
            while counts.get(val,0)>0:
                nums[index] = val
                index += 1
                counts[val] -= 1
        
        return nums
# @lc code=end

