#
# @lc app=leetcode id=778 lang=python3
#
# [778] Swim in Rising Water
#

# @lc code=start
import heapq
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        visit = set()
        minheap = [[grid[0][0],0,0]]
        directions = [[0,1],[1,0],[0,-1],[-1,0]]

        visit.add((0,0))

        while minheap:
            t,r,c = heapq.heappop(minheap)

            if r==n-1 and c==n-1:
                return t
            
            for dr,dc in directions:
                neighbourR, neighbourC = r+dr, c+dc
                if (neighbourR<0 or 
                    neighbourC<0 or 
                    neighbourR==n or 
                    neighbourC==n or 
                    (neighbourR,neighbourC) in visit):
                    continue
                visit.add((neighbourR,neighbourC))
                heapq.heappush(minheap,[max(t,grid[neighbourR][neighbourC]),neighbourR,neighbourC])
        
# @lc code=end

