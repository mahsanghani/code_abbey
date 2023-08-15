#
# @lc app=leetcode id=503 lang=python3
#
# [503] Next Greater Element II
#

# @lc code=start
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        results = [-1]*n
        stack = nums[::-1]

        for i in range(n-1,-1,-1):
            while stack and stack[-1]<=nums[i]:
                stack.pop()
            if stack:
                results[i] = stack[-1]
            stack.append(nums[i])
        return results
# @lc code=end

