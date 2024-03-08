#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#
# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i,j in enumerate(nums):
            comp = target - j
            if comp in d:
                return [d[comp],i]
            d[j] = i
        return []
# @lc code=end

