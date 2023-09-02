#
# @lc app=leetcode id=210 lang=python3
#
# [210] Course Schedule II
#

# @lc code=start
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        req = {c:[] for c in range(numCourses)}
        for course,prereq in prerequisites:
            req[course].append(prereq)

        visit,cycle,results = set(),set(),[]

        def dfs(course):
            if course in cycle:
                return False
            if course in visit:
                return True
            
            cycle.add(course)
            for pre in req[course]:
                if dfs(pre) == False:
                    return False
            cycle.remove(course)
            visit.add(course)
            results.append(course)
            return True
        
        for course in range(numCourses):
            if dfs(course) == False:
                return []
        return results
# @lc code=end

