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
import collections
from collections import deque
class Codec:
    # Encodes an n-ary tree to a binary tree.
    def encode(self, root: 'Optional[Node]') -> Optional[TreeNode]:
        if not root:
            return None
        
        rootNode = TreeNode(root.val)
        queue = deque([(rootNode, root)])

        while queue:
            parent, current = queue.popleft()
            prevBnode, headBnode = None, None

            for child in current.children:
                newBnode = TreeNode(child.val)
                if prevBnode:
                    prevBnode.right = newBnode
                else:
                    headBnode = newBnode
                prevBnode = newBnode
                queue.append((newBnode, child))
            
            parent.left = headBnode

        return rootNode
	
	# Decodes your binary tree to an n-ary tree.
    def decode(self, data: Optional[TreeNode]) -> 'Optional[Node]':
        if not data:
            return None
        
        rootNode = Node(data.val, [])
        queue = deque([(rootNode, data)])

        while queue:
            parent, current = queue.popleft()
            firstChild = current.left
            sibling = firstChild

            while sibling:
                newNode = Node(sibling.val, [])
                parent.children.append(newNode)
                queue.append((newNode, sibling))
                sibling = sibling.right

        return rootNode        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(root))
# @lc code=end

