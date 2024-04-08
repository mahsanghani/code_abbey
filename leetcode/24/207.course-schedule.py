#
# @lc app=leetcode id=207 lang=python3
#
# [207] Course Schedule
#
# @lc code=start
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = {i:[] for i in range(numCourses)}
        visit = set()
        for p,n in prerequisites:
            adj[p].append(n)

        def dfs(c):
            if not adj[c]:
                return True
            if c in visit:
                return False

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

