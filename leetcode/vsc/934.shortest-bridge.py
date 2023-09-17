#
# @lc app=leetcode id=934 lang=python3
#
# [934] Shortest Bridge
#

# @lc code=start
class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        visit = set()
        directions = [[0,1],[1,0],[0,-1],[-1,0]]

        def invalid(r,c):
            return r<0 or c<0 or r==rows or c==cols
        
        def dfs(r,c):
            if (invalid(r,c) or not grid[r][c] or (r,c) in visit):
                return
            visit.add((r,c))
            for dr,dc in directions:
                dfs(r+dr,c+dc)
                
        
# @lc code=end

