#
# @lc app=leetcode id=1557 lang=python3
#
# [1557] Minimum Number of Vertices to Reach All Nodes
#

# @lc code=start
import collections
from collections import defaultdict
class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        results = []
        incoming = collections.defaultdict(list)

        for source, destination in edges:
            incoming[destination].append(source)

        for i in range(n):
            if not incoming[i]:
                results.append(i)

        return results
# @lc code=end

