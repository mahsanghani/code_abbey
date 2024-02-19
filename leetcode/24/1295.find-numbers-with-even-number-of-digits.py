#
# @lc app=leetcode id=1295 lang=python3
#
# [1295] Find Numbers with Even Number of Digits
#

# @lc code=start
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        results = 0
        for num in nums:
            results += 1 if len(str(num))%2==0 else 0
        return results
# @lc code=end

