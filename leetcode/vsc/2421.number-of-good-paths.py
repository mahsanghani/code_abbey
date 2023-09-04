#
# @lc app=leetcode id=2421 lang=python3
#
# [2421] Number of Good Paths
#

# @lc code=start
import collections
from collections import defaultdict
class UnionFind:
    def __init__(self, n):
        self.par = list(range(n))
        self.rank = [0] * n

    def find(self, i):
        while i != self.par[i]:
            self.par[i] = self.par[self.par[i]]
            i = self.par[i]
        return i
    
    def union(self, a, b):
        aRoot = self.find(a)
        bRoot = self.find(b)

        if aRoot == bRoot:
            return False
        if self.rank[aRoot] < self.rank[bRoot]:
            self.par[aRoot] = bRoot
            self.rank[bRoot] += self.rank[aRoot]
        else:
            self.par[bRoot] = aRoot
            self.rank[aRoot] += self.rank[bRoot]
        return True

class Solution:
    def numberOfGoodPaths(self, vals: List[int], edges: List[List[int]]) -> int:
        n = len(vals)
        adj = collections.defaultdict(list)
        val2idx = collections.defaultdict(list)
        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)

        uf = UnionFind(n)
        results = n
        nodes = sorted([(vals[i], i) for i in range(n)])
        
# @lc code=end

