#
# @lc app=leetcode id=2778 lang=python3
#
# [2778] Sum of Squares of Special Elements 
#

# @lc code=start
class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        results = 0
        n = len(nums)
        for i in range(1,n+1):
            results += nums[i-1]*nums[i-1] if n%i==0 else 0
        return results
# @lc code=end

