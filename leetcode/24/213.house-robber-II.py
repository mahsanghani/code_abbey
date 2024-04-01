#
# @lc app=leetcode id=213 lang=python3
#
# [213] House Robber II
#
# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        return max(nums[0], self.dp(nums[1:]), self.dp(nums[:-1]))
        
    def dp(self, nums):
        one = 0
        two = 0

        for num in nums:
            temp = max(one+num,two)
            one = two
            two = temp
        
        return two
# @lc code=end

