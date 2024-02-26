#
# @lc app=leetcode id=1644 lang=python3
#
# [1644] Lowest Common Ancestor of a Binary Tree II
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def dfs(node, target):
            if not node:
                return False
            if node==target:
                return True
            return dfs(node.left,target) or dfs(node.right,target)
        
        def LCA(node, p, q):
            if not node or node==p or node==q:
                return node
            left = LCA(node.left,p,q)
            right = LCA(node.right,p,q)
            return node if left and right else left or right
        
        results = LCA(root,p,q)
        if results==p:
            return p if dfs(p,q) else None
        elif results==q:
            return q if dfs(q,p) else None
        else:
            return results
# @lc code=end

