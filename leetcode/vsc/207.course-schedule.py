#
# @lc app=leetcode id=207 lang=python3
#
# [207] Course Schedule
#

# @lc code=start
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        req = {i:[] for i in range(numCourses)}
        for course,prereq in prerequisites:
            req[course].append(prereq)

        visit=set()

        def dfs(course):
            if course in visit:
                return False
            if req[course]==[]:
                return True
            
            visit.add(course)
            for pre in req[course]:
                if not dfs(pre):
                    return False
            visit.remove(course)
            req[course] = []
            return True
        
        for course in range(numCourses):
            if not dfs(course):
                return False
        
        return True
# @lc code=end

