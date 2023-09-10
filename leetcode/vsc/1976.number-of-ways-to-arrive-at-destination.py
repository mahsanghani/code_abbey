#
# @lc app=leetcode id=1976 lang=python3
#
# [1976] Number of Ways to Arrive at Destination
#

# @lc code=start
import heapq
class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        graph = {}
        for u,v,t in roads:
            graph.setdefault(u,[]).append((v,t))
            graph.setdefault(v,[]).append((u,t))

        dist = [inf]*n
        dist[0] = 0
        ways = [0]*n
        ways[0] = 1
        pq = [(0,0)]

        while pq:
            d,u = heapq.heappop(pq)
            if d > dist[-1]:
                break
            if d == dist[u]:
                for v,t in graph.get(u,[]):
                    if dist[u] + t < dist[v]:
                        dist[v] = dist[u] + t
                        ways[v] = ways[u]
                        heapq.heappush(pq, (dist[v], v))
                    elif dist[u] + t == dist[v]:
                        ways[v] += ways[u]
        
        return ways[-1] % 1_000_000_007

# @lc code=end

