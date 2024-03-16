#
# @lc app=leetcode id=133 lang=python3
#
# [133] Clone Graph
#
# @lc code=start
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

from typing import Optional
class Solution:
    def __init__(self):
        self.visit = {}

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return node
        if node in self.visit:
            return self.visit[node]
        
        clone = Node(node.val)
        self.visit[node] = clone

        if node.neighbors:
            clone.neighbors = [self.cloneGraph(node) for node in node.neighbors]
        
        return clone

# @lc code=end

