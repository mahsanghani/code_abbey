#
# @lc app=leetcode id=1379 lang=python3
#
# [1379] Find a Corresponding Node of a Binary Tree in a Clone of That Tree
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        def preorder(original: TreeNode, cloned: TreeNode):
            if original:
                if original is target:
                    self.results = cloned
                preorder(original.left, cloned.left)
                preorder(original.right, cloned.right)
        preorder(original,cloned)
        return self.results
# @lc code=end

