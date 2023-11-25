#
# @lc app=leetcode id=463 lang=python3
#
# [463] Island Perimeter
#

# @lc code=start
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        visit = set()

        def dfs(i,j):
            if (i,j) in visit:
                return 0
            if i<0 or j<0 or i>=len(grid) or j>=len(grid[0]) or grid[i][j]==0:
                return 1
            
            visit.add((i,j))

            perimeter = dfs(i,j+1)
            perimeter += dfs(i,j-1)
            perimeter += dfs(i-1,j)
            perimeter += dfs(i+1,j)

            return perimeter
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    return dfs(i,j)

# @lc code=end

