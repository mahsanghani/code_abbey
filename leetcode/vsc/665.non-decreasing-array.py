#
# @lc app=leetcode id=665 lang=python3
#
# [665] Non-decreasing Array
#

# @lc code=start
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        d=-1
        for i in range(len(nums)-1):
            if nums[i]<=nums[i+1]:
                continue
            if d==0:
                return False
            if i==0 or nums[i+1] >= nums[i-1]:
                nums[i] = nums[i+1]
            else:
                nums[i+1] = nums[i]
            d+=1
        return True

# @lc code=end

