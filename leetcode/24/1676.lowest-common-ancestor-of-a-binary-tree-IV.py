#
# @lc app=leetcode id=1676 lang=python3
#
# [1676] Lowest Common Ancestor of a Binary Tree IV
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', nodes: 'List[TreeNode]') -> 'TreeNode':
        nodes = set(nodes)
        def dfs(node):
            if not node or node in nodes:
                return node
            left = dfs(node.left)
            right = dfs(node.right)
            return node if left and right else left or right
        return dfs(root)
# @lc code=end

