#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#
# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i,num in enumerate(nums):
            comp = target - num
            if comp in d:
                return [d[comp], i]
            d[num] = i
        return []
# @lc code=end

