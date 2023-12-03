#
# @lc app=leetcode id=1038 lang=python3
#
# [1038] Binary Search Tree to Greater Sum Tree
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        nodes = []

        def inorderTraversal(node):
            nonlocal nodes
            if node:
                inorderTraversal(node.left)
                nodes.append(node.val)
                inorderTraversal(node.right)
        
        inorderTraversal(root)

        def updateValue(node):
            nonlocal nodes
            if node:
                updateValue(node.left)
                node.val = sum(nodes[node.val:])
                updateValue(node.right)

        updateValue(root)
        return root
# @lc code=end

