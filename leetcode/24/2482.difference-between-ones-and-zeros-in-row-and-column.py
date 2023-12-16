#
# @lc app=leetcode id=2482 lang=python3
#
# [2482] Difference Between Ones and Zeros in Row and Column
#

# @lc code=start
class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        results = []

        for i in range(len(grid)):
            new = []
            for j in range(len(grid[0])):
                row = grid[i]
                col = [row[j] for row in grid]
                new.append(row.count(1)+col.count(1)-row.count(0)-col.count(0))
            results.append(new)

        return results
        
# @lc code=end

