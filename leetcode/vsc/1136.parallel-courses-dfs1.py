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

        def dfs(c: int) -> bool:
            if c in visit:
                return visit[c]
            else:
                visit[c] = -1
            for end in adj[c]:
                if dfs(end):
                    return True
            visit[c] = False
            return False
        
        for j in adj:
            if dfs(j):
                return -1
            
        visit_length = {}

        def dfs_max_path(c: int) -> int:
            if c in visit_length:
                return visit_length[c]
            max_length = 1
            for end in adj[c]:
                length = dfs_max_path(end)
                max_length = max(length+1, max_length)
            visit_length[c] = max_length
            return max_length
        
        return max(dfs_max_path(c) for c in adj)

# @lc code=end

