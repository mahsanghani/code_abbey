#
# @lc app=leetcode id=1905 lang=python3
#
# [1905] Count Sub Islands
#
# @lc code=start
class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        rows = len(grid1)
        cols = len(grid1[0])
        visit = set()
        islands = 0

        def dfs(r,c):
            if r<0 or c<0 or r==rows or c==cols or (r,c) in visit or grid2[r][c]==0:
                return True

            visit.add((r,c))
            results = True

            if grid1[r][c]==0:
                results = False

            results = dfs(r-1,c) and results
            results = dfs(r+1,c) and results
            results = dfs(r,c-1) and results
            results = dfs(r,c+1) and results

            return results

        for r in range(rows):
            for c in range(cols):
                if grid2[r][c] and (r,c) not in visit and dfs(r,c):
                    islands+=1

        return islands
# @lc code=end

