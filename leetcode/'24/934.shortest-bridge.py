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
        
        bfs1 = [(x,y)]
        bfs2 = [(x,y)]
        grid[x][y] = 2
        distance = 0
        
        while bfs1:
            new_bfs = []
            for x,y in bfs1:
                for i,j in [(x+1,y),(x-1,y),(x,y+1),(x,y-1)]:
                    if 0 <= i < n and 0 <= j < n and grid[i][j] == 1:
                        new_bfs.append((i,j))
                        bfs2.append((i,j))
                        grid[i][j] = 2
            bfs1 = new_bfs

        while bfs2:
            new_bfs = []
            for x,y in bfs2:
                for i,j in [(x+1,y),(x-1,y),(x,y+1),(x,y-1)]:
                    if 0 <= i < n and 0 <= j < n:
                        if grid[i][j] == 1:
                            return distance
                        elif grid[i][j] == 0:
                            new_bfs.append((i,j))
                            grid[i][j] = -1

            bfs2 = new_bfs
            distance += 1
                
# @lc code=end

