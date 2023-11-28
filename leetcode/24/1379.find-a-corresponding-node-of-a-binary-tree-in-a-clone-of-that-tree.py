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
        stack_original = []
        stack_cloned = []
        node_original = original
        node_cloned = cloned

        while stack_original or node_cloned:
            while node_original:
                stack_original.append(node_original)
                stack_cloned.append(node_cloned)
                
                node_original = node_original.left
                node_cloned = node_cloned.left

            node_original = stack_original.pop()
            node_cloned = stack_cloned.pop()

            if node_original is target:
                return node_cloned

            node_original = node_original.right
            node_cloned = node_cloned.right

