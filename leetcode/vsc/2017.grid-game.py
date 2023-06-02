#
# @lc app=leetcode id=2017 lang=python3
#
# [2017] Grid Game
#

# @lc code=start
class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        n = len(grid[0])
        pre1 = grid[0].copy()
        pre2 = grid[1].copy()

        for i in range(1, n):
            pre1[i] += pre1[i-1]
            pre2[i] += pre2[i-1]

        results = float("inf")
        for i in range(n):
            top = pre1[-1] - pre1[i]
            bottom = pre2[i-1]
            second = max(top, bottom)
            results = min(results, second)

        return results
# @lc code=end

