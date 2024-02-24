#
# @lc app=leetcode id=200 lang=python3
#
# [200] Number of Islands
#

# @lc code=start
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        visit = set()
        islands = 0

        def dfs(r,c):
            if r<0 or c<0 or r==rows or c==cols or (r,c) in visit or grid[r][c]=="0":
                return 0
            
            visit.add((r,c))

            dfs(r+1,c)
            dfs(r,c+1)
            dfs(r-1,c)
            dfs(r,c-1)

            return 1

        for r in range(rows):
            for c in range(cols):
                if (r,c) not in visit and grid[r][c]=="1":
                    islands += dfs(r,c)
        return islands
# @lc code=end

