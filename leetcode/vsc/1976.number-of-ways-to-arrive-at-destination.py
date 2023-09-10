#
# @lc app=leetcode id=1976 lang=python3
#
# [1976] Number of Ways to Arrive at Destination
#

# @lc code=start
import heapq
class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        adj = [[] for i in range(n)]
        for u,v,t in roads:
            adj[u].append((v,t))
            adj[v].append((u,t))

        dist = [float('inf')]*n
        dist[0] = 0
        ways = [0]*n
        ways[0] = 1

        pq = []
        heapq.heapify(pq)
        heapq.heappush(pq,(0,0))
        mod = 10**9+7

        while pq:
            time, node = heapq.heappop(pq)
            for v,t in adj[node]:
                if dist[v] > t+time:
                    dist[v] = t+time
                    heapq.heappush(pq,(dist[v],v))
                    ways[v] = ways[node]
                elif dist[v] == t+time:
                    ways[v] = (ways[v]+ways[node])%mod
        
        return ways[n-1] % mod

# @lc code=end

