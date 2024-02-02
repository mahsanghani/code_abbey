#
# @lc app=leetcode id=1913 lang=python3
#
# [1913] Maximum Product Difference Between Two Pairs
#

# @lc code=start
class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        nums.sort()
        return abs((nums[0]*nums[1])-(nums[len(nums)-1]*nums[len(nums)-2]))
# @lc code=end

