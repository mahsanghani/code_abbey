#
# @lc app=leetcode id=994 lang=python3
#
# [994] Rotting Oranges
#

# @lc code=start
import collections
from collections import deque
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        time,fresh,q,rows,cols=0,0,deque(),len(grid),len(grid[0])
        directions=[[1,0],[0,1],[-1,0],[0,-1]]

        for r in range(rows):
            for c in range(cols):
                if grid[r][c]==1:
                    fresh+=1
                if grid[r][c]==2:
                    q.append([r,c])

        while q and fresh>0:
            for i in range(len(q)):
                row,col=q.popleft()
                for dr,dc in directions:
                    r=row+dr
                    c=col+dc
                    if r<0 or c<0 or r==rows or c==cols or grid[r][c]!=1:
                        continue
                    grid[r][c]=2
                    q.append([r,c])
                    fresh-=1

            time+=1
        return time if fresh==0 else -1
# @lc code=end

