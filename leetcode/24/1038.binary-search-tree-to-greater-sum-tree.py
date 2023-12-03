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
        self.nodes = []
        self.total = 0

        def inorderTraversal(node):
            if node:
                inorderTraversal(node.left)
                self.nodes.append(node.val)
                inorderTraversal(node.right)
        
        inorderTraversal(root)

        def updateValue(node):
            if node:
                updateValue(node.right)
                node.val = self.total = self.total + node.val
                updateValue(node.left)

        updateValue(root)
        return root
# @lc code=end

