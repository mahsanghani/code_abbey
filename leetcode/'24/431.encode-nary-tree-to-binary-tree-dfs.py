#
# @lc app=leetcode id=431 lang=python3
#
# [431] Encode N-ary Tree to Binary Tree
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

"""
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
"""

class Codec:
    # Encodes an n-ary tree to a binary tree.
    def encode(self, root: 'Optional[Node]') -> Optional[TreeNode]:
        if not root:
            return None
        
        rootNode = TreeNode(root.val)
        if len(root.children) > 0:
            firstChild = root.children[0]
            rootNode.left = self.encode(firstChild)

        current = rootNode.left

        for i in range(1, len(root.children)):
            current.right = self.encode(root.children[i])
            current = current.right

        return rootNode
	
	# Decodes your binary tree to an n-ary tree.
    def decode(self, data: Optional[TreeNode]) -> 'Optional[Node]':
        if not data:
            return None
        
        rootNode = Node(data.val, [])
        current = data.left
        while current:
            rootNode.children.append(self.decode(current))
            current = current.right

        return rootNode

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(root))
# @lc code=end

