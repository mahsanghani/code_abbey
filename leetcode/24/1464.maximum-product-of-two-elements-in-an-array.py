#
# @lc app=leetcode id=1464 lang=python3
#
# [1464] Maximum Product of Two Elements in an Array
#

# @lc code=start
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        nums.sort()
        return (nums[len(nums)-1]-1)*(nums[len(nums)-2]-1)
# @lc code=end

