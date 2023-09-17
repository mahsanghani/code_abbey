#
# @lc app=leetcode id=934 lang=python3
#
# [934] Shortest Bridge
#

# @lc code=start
import collections
from collections import deque
class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        n = len(grid)
        x,y = -1,-1
        
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    x,y = i,j
                    break

        def dfs(x,y):
            grid[x][y] = 2
            bfs.append((x,y))
            for x,y in [(x+1,y),(x-1,y),(x,y+1),(x,y-1)]:
                if 0 <= x < n and 0 <= y < n and grid[x][y] == 1:
                    dfs(x,y)
        
        bfs = []
        dist = 0
        dfs(x,y)

        while bfs:
            new_bfs = []
            for x,y in bfs:
                for i,j in [(x+1,y),(x-1,y),(x,y+1),(x,y-1)]:
                    if 0 <= i < n and 0 <= j < n:
                        if grid[i][j] == 1:
                            return dist
                        elif grid[i][j] == 0:
                            new_bfs.append((i,j))
                            grid[i][j] = -1
            
            bfs = new_bfs
            dist += 1
                
# @lc code=end

