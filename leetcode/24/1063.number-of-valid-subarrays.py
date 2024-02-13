#
# @lc app=leetcode id=1063 lang=python3
#
# [1063] Number of Valid Subarrays
#
# @lc code=start
class Solution:
    def validSubarrays(self, nums: List[int]) -> int:
        stack = []
        results = 0

        for num in nums:
            while stack and num<stack[-1]:
                stack.pop()
            stack.append(num)
            results+=len(stack)

        return results
# @lc code=end

