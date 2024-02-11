#
# @lc app=leetcode id=1485 lang=python3
#
# [1485] Clone Binary Tree With Random Pointer
#

# @lc code=start# Definition for Node.
class Node:
    def __init__(self, val=0, left=None, right=None, random=None):
        self.val = val
        self.left = left
        self.right = right
        self.random = random

class Solution:
    def __init__(self):
        self.seen: dict[str, int] = {None: None}

    def dfs(self, node: 'Optional[Node]') -> 'Optional[NodeCopy]':
        if not node:
            return None
        if self.seen.get(node):
            return self.seen.get(node)
        

    def copyRandomBinaryTree(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        return None
# @lc code=end

