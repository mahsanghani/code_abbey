#
# @lc app=leetcode id=1462 lang=python3
#
# [1462] Course Schedule IV
#

# @lc code=start
class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        adj = defaultdict(list)
        for req,crs in prerequisites:
            adj[crs].append(req)

        def dfs(crs):
            if crs not in prereqmap:
                prereqmap[crs] = set()
                for prereq in adj[crs]:
                    # union of hashsets
                    prereqmap[crs] |= dfs(prereq)
                prereqmap[crs].add(crs)
            return prereqmap[crs]
        
        prereqmap = {}

        for crs in range(numCourses):
            dfs(crs)

        results = []
        for u,v in queries:
            results.append(u in prereqmap[v])
        return results
# @lc code=end

