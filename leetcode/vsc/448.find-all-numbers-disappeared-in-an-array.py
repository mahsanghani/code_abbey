#
# @lc app=leetcode id=448 lang=python3
#
# [448] Find All Numbers Disappeared in an Array
#

# @lc code=start
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        res=[]
        n=len(nums)
        check = set(range(1,n+1))
        numset = set(nums)
        return list(check.difference(numset))
# @lc code=end

