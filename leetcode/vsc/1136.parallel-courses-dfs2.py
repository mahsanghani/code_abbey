#
# @lc app=leetcode id=1136 lang=python3
#
# [1136] Parallel Courses
#

# @lc code=start
class Solution:
    def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
        adj = {i:[] for i in range(1,n+1)}
        count = {i:0 for i in range(1,n+1)}
        for start,end in relations:
            adj[start].append(end)
            count[end] += 1

        queue = []
        for node in adj:
            if count[node] == 0:
                queue.append(node)

        step = 0
        study = 0

        while queue:
            step += 1
            next_queue = []
            for node in queue:
                study += 1
                end = adj[node]
                for e in end:
                    count[e] -= 1
                    if count[e] == 0:
                        next_queue.append(e)
            queue = next_queue

        return step if study == n else -1

# @lc code=end

