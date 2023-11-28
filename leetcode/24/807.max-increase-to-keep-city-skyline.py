#
# @lc app=leetcode id=807 lang=python3
#
# [807] Max Increase to Keep City Skyline
#

# @lc code=start
class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        n = len(grid)
        rows = [0]*n
        cols = [0]*n
        results = 0

        for r in range(n):
            for c in range(n):
                rows[r] = max(rows[r], grid[r][c])
                cols[c] = max(cols[c], grid[r][c])

        for r in range(n):
            for c in range(n):
                results += min(rows[r],cols[c]) - grid[r][c]

        return results
# @lc code=end

