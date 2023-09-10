#
# @lc app=leetcode id=210 lang=python3
#
# [210] Course Schedule II
#

# @lc code=start
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = {i:[] for i in range(numCourses)}
        for prev, next in prerequisites:
            adj[prev].append(next)

        visit = set()
        cycle = set()
        results = []

        def dfs(c):
            if c in visit:
                return True
            if c in cycle:
                return False
            
            cycle.add(c)

            for j in adj[c]:
                if dfs(j)==False:
                    return False
            
            visit.add(c)
            cycle.remove(c)
            results.append(c)
            return True
        
        for j in range(numCourses):
            if dfs(j)==False:
                return []
            
        return results

# @lc code=end

