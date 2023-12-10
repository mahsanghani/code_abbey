#
# @lc app=leetcode id=1490 lang=python3
#
# [1490] Clone N-ary Tree
#

# @lc code=start

# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

class Solution:
    def cloneTree(self, root: 'Node') -> 'Node':
        if not root:
            return None
        
        node = Node(root.val)
        node.children = [self.cloneTree(child) for child in node.children]

        return node
# @lc code=end

