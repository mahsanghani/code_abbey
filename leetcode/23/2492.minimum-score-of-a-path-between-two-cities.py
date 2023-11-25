#
# @lc app=leetcode id=2492 lang=python3
#
# [2492] Minimum Score of a Path Between Two Cities
#

# @lc code=start
import collections
from collections import defaultdict
class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        adj = collections.defaultdict(list)
        results = float("inf")
        visit = set()
        
        for src,dst,dist in roads:
            adj[src].append((dst, dist))
            adj[dst].append((src, dist))

        def dfs(i):
            if i in visit:
                return
            visit.add(i)
            nonlocal results
            for neighbour, distance in adj[i]:
                results = min(results, distance)
                dfs(neighbour)
        
        dfs(1)
        return results

# @lc code=end

