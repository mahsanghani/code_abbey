#
# @lc app=leetcode id=1136 lang=python3
#
# [1136] Parallel Courses
#

# @lc code=start
class Solution:
    def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
        adj = {i:[] for i in range(1,n+1)}
        for start, end in relations:
            adj[start].append(end)

        visit = {}

        def dfs(c):
            if c in visit:
                return visit[c]
            else:
                visit[c] = -1

            max_length = 1

            for end in adj[c]:
                length = dfs(end)
                if length == -1:
                    return -1
                else:
                    max_length = max(length+1, max_length)
            
            visit[c] = max_length
            return max_length
        
        max_length = -1
        for c in adj:
            length = dfs(c)
            if length == -1:
                return -1
            else:
                max_length = max(length, max_length)
        return max_length

# @lc code=end

