#
# @lc app=leetcode id=210 lang=python3
#
# [210] Course Schedule II
#
# @lc code=start
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = {i:[] for i in range(numCourses)}
        visit = set()
        cycles = set()
        results = []
        for p,n in prerequisites:
            adj[p].append(n)

        def dfs(c):
            if c in visit:
                return True
            if c in cycles:
                return False

            cycles.add(c)

            for j in adj[c]:
                if dfs(j)==False:
                    return False

            visit.add(c)
            cycles.remove(c)
            results.append(c)

        for j in range(numCourses):
            if dfs(j)==False:
                return []

        return results
# @lc code=end

