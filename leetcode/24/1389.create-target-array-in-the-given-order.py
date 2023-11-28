#
# @lc app=leetcode id=1389 lang=python3
#
# [1389] Create Target Array in the Given Order
#

# @lc code=start
class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        results = []
        for i in range(len(nums)):
            results.insert(index[i],nums[i])
        return results
# @lc code=end

