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
        if not grid:
            return 0
        
        rows = len(grid)
        cols = len(grid[0])
        visit = set()
        islands = 0

        def bfs(r,c):
            q=collections.deque()
            visit.add((r,c))
            q.append((r,c))

            while q:
                row,col = q.popleft()
                directions = [[0,1],[1,0],[0,-1],[-1,0]]

                for dr, dc in directions:
                    r,c = row+dr,col+dc
                    if (r in range(rows) and 
                        c in range(cols) and 
                        grid[r][c] == "1" and
                        (r,c) not in visit):
                        visit.add((r,c))
                        q.append((r,c))

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1" and (r,c) not in visit:
                    bfs(r,c)
                    islands+=1

        return islands

# @lc code=end

