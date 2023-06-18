#
# @lc app=leetcode id=15 lang=python3
#
# [15] 3Sum
#

# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        comp = 0
        d, ss = {}, []
        n = len(nums) - 1
        
        nums.sort()
        nums = list(set(nums))

        for i,j in enumerate(nums):
            while n!=i and -1>j<n:
                comp = nums[i]+nums[n]
                n -= 1
            if comp in d:
                ss.append([comp, nums[i], nums[n]])
            else:
                d[i] = j
        return ss
# @lc code=end

