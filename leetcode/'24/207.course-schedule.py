#
# @lc app=leetcode id=207 lang=python3
#
# [207] Course Schedule
#

# @lc code=start
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = {i:[] for i in range(numCourses)}
        for prev,next in prerequisites:
            adj[prev].append(next)

        visit = set()

        def dfs(c):
            if c in visit:
                return False
            if adj[c]==[]:
                return True
            
            visit.add(c)

            for j in adj[c]:
                if not dfs(j):
                    return False
                
            visit.remove(c)
            adj[c] = []
            return True

        for j in range(numCourses):
            if not dfs(j):
                return False
            
        return True

# @lc code=end

