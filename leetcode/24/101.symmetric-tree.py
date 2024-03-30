#
# @lc app=leetcode id=101 lang=python3
#
# [101] Symmetric Tree
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def dfs(p,q):
            while p and q:
                return p.val==q.val and dfs(p.left,q.right) and dfs(p.right,q.left)
            return p is q

        return dfs(root.left,root.right)
# @lc code=end

