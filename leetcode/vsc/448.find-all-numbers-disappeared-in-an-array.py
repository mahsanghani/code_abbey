#
# @lc app=leetcode id=448 lang=python3
#
# [448] Find All Numbers Disappeared in an Array
#

# @lc code=start
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        check = set(range(1,len(nums)+1))
        return list(check.difference(set(nums)))
# @lc code=end

