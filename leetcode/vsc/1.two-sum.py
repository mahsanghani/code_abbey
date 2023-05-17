#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d={}
        for i,j in enumerate(nums):
            if target-j in d:
                return [i,d[target-j]]
            d[j]=i
# @lc code=end

