#
# @lc app=leetcode id=1976 lang=python3
#
# [1976] Number of Ways to Arrive at Destination
#

# @lc code=start
import math
import heapq
from heapq import heappop, heappush
import collections
from collections import defaultdict
class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        adj = collections.defaultdict(list)

        for u,v,t in roads:
            adj[u].append([v,t])
            adj[v].append([u,t])
        
        def djikstra(src):
            minHeap = [(0, src)]
            
            dist = [math.inf]*n
            ways = [0]*n
            dist[src] = 0
            ways[src] = 1

            while minHeap:
                d, u = heapq.heappop(minHeap)
                if dist[u] < d:
                    continue
                for v,t in adj[u]:
                    if dist[v] > t+d:
                        dist[v] = t+d
                        ways[v] = ways[u]
                        heapq.heappush(minHeap, (dist[v],v))
                    elif dist[v] == d+t:
                        ways[v] = (ways[v] + ways[u]) % 1_000_000_007
            return ways[n-1]
        
        return djikstra(0)

# @lc code=end

