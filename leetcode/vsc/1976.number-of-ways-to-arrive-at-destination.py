#
# @lc app=leetcode id=1976 lang=python3
#
# [1976] Number of Ways to Arrive at Destination
#

# @lc code=start
class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        graph = {}
        for u,v,t in roads:
            graph.setdefault(u, {})[v] = t
            graph.setdefault(v, {})[u] = t

        dist = [inf]*n
        dist[-1] = 0
        stack = [(n-1, 0)]

        while stack:
            x, t = stack.pop()
            if t == dist[x]:
                for y in graph.get(x, {}):
                    if t + graph[x][y] < dist[y]:
                        dist[y] = t + graph[x][y]
                        stack.append((y, t + graph[x][y]))

        @cache
        def fn(x):
            if x == n-1:
                return 1
            if dist[x] == inf:
                return 0
            answer = 0
            for y in graph.get(x, {}):
                if graph[x][y] + dist[y] == dist[x]:
                    answer += fn(y)
            return answer % 1_000_000_007
        
        return fn(0)

# @lc code=end

