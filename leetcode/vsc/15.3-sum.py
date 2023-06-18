#
# @lc app=leetcode id=15 lang=python3
#
# [15] 3Sum
#

# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        for i,j in enumerate(nums):
            if i > 0 and j == nums[i-1]:
                continue
            
            l = i + 1
            r = len(nums) - 1
            
            while l<r:
                three = j + nums[l] + nums[r]
                if three > 0:
                    r -= 1
                elif three < 0:
                    l += 1
                else:
                    res.append([j, nums[l], nums[r]])
                    l += 1
                    while nums[l] == nums[l-1] and l<r:
                        l += 1
        return res
# @lc code=end

