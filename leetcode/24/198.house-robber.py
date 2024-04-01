#
# @lc app=leetcode id=198 lang=python3
#
# [198] House Robber
#
# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        one = 0
        two = 0

        for num in nums:
            temp = max(one+num,two)
            one = two
            two = temp

        return two
# @lc code=end

