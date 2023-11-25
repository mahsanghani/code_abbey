#
# @lc app=leetcode id=1514 lang=python3
#
# [1514] Path with Maximum Probability
#

# @lc code=start
import heapq
import collections
from collections import defaultdict
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        adj = collections.defaultdict(list)

        for i in range(len(edges)):
            src, dst = edges[i]
            adj[src].append([dst, succProb[i]])
            adj[dst].append([src, succProb[i]])

        pq = [(-1, start_node)]
        visit = set()

        while pq:
            prob, curr = heapq.heappop(pq)
            visit.add(curr)

            if curr == end_node:
                return prob*-1
            for neighbour, edgePath in adj[curr]:
                if neighbour not in visit:
                    heapq.heappush(pq, (prob*edgePath, neighbour))

        return 0   

# @lc code=end

