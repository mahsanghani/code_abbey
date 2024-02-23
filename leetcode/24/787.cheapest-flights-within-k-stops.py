#
# @lc app=leetcode id=787 lang=python3
#
# [787] Cheapest Flights Within K Stops
#
# @lc code=start
from collections import deque,defaultdict
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        adj = defaultdict(list)
        for s,d,p in flights:
            adj[s].append((d,p))

        queue = deque()
        queue.append((src,0))
        costs = [float("inf")]*n

        while queue and k>=0:
            m = len(queue)
            for _ in range(m):
                curr, cost = queue.popleft()
                for node, price in adj[curr]:
                    if cost+price<costs[node]:
                        costs[node]=cost+price
                        queue.append((node,costs[node]))
            k-=1
        return costs[dst] if costs[dst]!=float("inf") else -1

# @lc code=end

