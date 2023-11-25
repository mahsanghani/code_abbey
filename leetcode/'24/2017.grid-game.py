#
# @lc app=leetcode id=2017 lang=python3
#
# [2017] Grid Game
#

# @lc code=start
class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        left = 0
        right = sum(grid[0])
        results = float("inf")

        for x, y in zip(grid[0], grid[1]):
            right -= x
            results = min(results, max(left, right))
            left += y
        return results
# @lc code=end

