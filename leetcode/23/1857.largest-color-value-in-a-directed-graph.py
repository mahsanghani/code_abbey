#
# @lc app=leetcode id=1857 lang=python3
#
# [1857] Largest Color Value in a Directed Graph
#

# @lc code=start
import collections
from collections import defaultdict
class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        adj = collections.defaultdict(list)
        for src,dst in edges:
            adj[src].append(dst)

        n,results,path,visit = len(colors),0,set(),set()
        count = [[0]*26 for i in range(n)]
        
        def dfs(node):
            if node in path:
                return float("inf")
            if node in visit:
                return 0
            
            visit.add(node)
            path.add(node)

            colorIndex = ord(colors[node])-ord('a')
            count[node][colorIndex] = 1

            for neighbor in adj[node]:
                if dfs(neighbor)==float("inf"):
                    return float("inf")
                for c in range(26):
                    count[node][c] = max(
                        count[node][c],
                        (1 if c==colorIndex else 0) + count[neighbor][c]
                    )

            path.remove(node)
            return max(count[node])

        for i in range(n):
            results=max(results,dfs(i))

        return -1 if results==float("inf") else results
# @lc code=end

