#
# @lc app=leetcode id=665 lang=python3
#
# [665] Non-decreasing Array
#

# @lc code=start
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        d=-1
        for i in range(1,len(nums)-1):
            if nums[i]>nums[i-1] or nums[i]>nums[i+1]:
                if d==0:
                    return False
                else:
                    d+=1
            else:
                continue
        return True
# @lc code=end

