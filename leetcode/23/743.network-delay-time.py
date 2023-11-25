#
# @lc app=leetcode id=743 lang=python3
#
# [743] Network Delay Time
#

# @lc code=start
import heapq
import collections
from collections import defaultdict
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        edges = collections.defaultdict(list)

        for u,v,w in times:
            edges[u].append((v,w))

        time = 0
        visit = set()
        minheap = [(0,k)]

        while minheap:
            w1,n1 = heapq.heappop(minheap)
            if n1 in visit:
                continue
            visit.add(n1)
            time = max(time,w1)

            for n2,w2 in edges[n1]:
                if n2 not in visit:
                    heapq.heappush(minheap, (w1+w2,n2))
        
        return time if len(visit)==n else -1

# @lc code=end

