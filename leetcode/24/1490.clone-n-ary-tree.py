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
            return root
        
        node = Node(root.val)

        for child in root.children:
            node.children.append(self.cloneTree(child))

        return node
# @lc code=end

