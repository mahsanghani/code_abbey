#
# @lc app=leetcode id=1579 lang=python3
#
# [1579] Remove Max Number of Edges to Keep Graph Fully Traversable
#

# @lc code=start
import collections
from collections import defaultdict
class UnionFind:
    def __init__(self, n):
        self.n = n
        self.par = [i for i in range(n+1)]
        self.rank = [1] * (n + 1)

    def find(self, x):
        while x != self.par[x]:
            self.par[x] = self.par[self.par[x]]
            x = self.par[x]
        return x
    
    def isConnected(self):
        return self.n <= 1
    
    def union(self, x, y):
        p1 = self.find(x)
        p2 = self.find(y)
        if p1 == p2:
            return 0
        if self.rank[p1] > self.rank[p2]:
            self.rank[p1] += self.rank[p2]
            self.par[p2] = p1
        else:
            self.rank[p2] += self.rank[p1]
            self.par[p1] = p2
        self.n -= 1
        return 1

class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        count = 0
        bob = UnionFind(n)
        alice = UnionFind(n)

        for time, source, destination in edges:
            if time == 3:
                count += (alice.union(source, destination) | bob.union(source, destination))

        for time, source, destination in edges:
            if time == 1:
                count += alice.union(source, destination)
            elif time == 2:
                count += bob.union(source, destination)

        if bob.isConnected() and alice.isConnected():
            return len(edges) - count
        return -1
# @lc code=end

