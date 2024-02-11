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

    def dfs(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        if not root:
            return None
        if self.seen.get(root):
            return self.seen.get(root)
        
        node = self.NodeCopy(root.val)
        self.seen[root] = node

        node.left = self.dfs(root.left)
        node.right = self.dfs(root.right)
        node.random = self.random(root.random)
        return node

    def copyRandomBinaryTree(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        return None
# @lc code=end

