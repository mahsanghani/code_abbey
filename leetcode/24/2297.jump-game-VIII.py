#
# @lc app=leetcode id=2297 lang=python3
#
# [2297] Jump Game VIII
#
# @lc code=start
import math
class Solution:
    def minCost(self, nums: List[int], costs: List[int]) -> int:
        # monotonic stack dynamic programming
        n = len(nums)
        ng,nl = []*n,[]*n
        dp = [math.inf]*n
        dp[0] = 0

        for i in range(n):
            while ng and nums[ng[-1]] <= nums[i]:
                dp[i] = min(dp[i], dp[ng.pop()] + costs[i])
            while nl and nums[nl[-1]] > nums[i]:
                dp[i] = min(dp[i], dp[nl.pop()] + costs[i])
            ng.append(i)
            nl.append(i)
        return dp[n-1]
# @lc code=end

