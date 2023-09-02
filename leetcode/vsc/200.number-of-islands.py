#
# @lc app=leetcode id=200 lang=python3
#
# [200] Number of Islands
#

# @lc code=start
import collections
from collections import deque
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rows,cols,visit,islands=len(grid),len(grid[0]),set(),0

        def dfs(r,c):
            if r<0 or c<0 or r==rows or c==cols or (r,c) in visit or grid[r][c]!="1":
                return 0
            
            visit.add((r,c))

            dfs(r,c+1)
            dfs(r,c-1)
            dfs(r-1,c)
            dfs(r+1,c)

        for r in range(rows):
            for c in range(cols):
                if grid[r][c]=="1" and (r,c) not in visit:
                    dfs(r,c)
                    islands+=1

        return islands


# @lc code=end

