#
# @lc app=leetcode id=286 lang=python3
#
# [286] Walls and Gates
#
# @lc code=start
from collections import deque
class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        rows = len(rooms)
        cols = len(rooms[0])
        q = deque()
        visit = set()
        distance = 0

        def dfs(r,c):
            if r<0 or c<0 or r==rows or c==cols or (r,c) in visit or rooms[r][c]==-1:
                return
            q.append((r,c))
            visit.add((r,c))

        for r in range(rows):
            for c in range(cols):
                if rooms[r][c]==0:
                    q.append((r,c))
                    visit.add((r,c))

        while q:
            for i in range(len(q)):
                r,c = q.popleft()
                rooms[r][c] = distance
                dfs(r+1,c)
                dfs(r,c+1)
                dfs(r-1,c)
                dfs(r,c-1)
            distance+=1
# @lc code=end

