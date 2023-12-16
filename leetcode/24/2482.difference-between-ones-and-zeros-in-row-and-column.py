#
# @lc app=leetcode id=2482 lang=python3
#
# [2482] Difference Between Ones and Zeros in Row and Column
#

# @lc code=start
class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        rows = []
        cols = []
        results = grid

        for i in range(len(grid)):
            rows.append(grid[i].count(1))
        
        for j in range(len(grid[0])):
            cols.append(sum([row[j] for row in grid]))

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                results[i][j] = 2*rows[i]+2*cols[j]-len(grid)-len(grid[i])

        return results
# @lc code=end

