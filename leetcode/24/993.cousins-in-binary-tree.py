#
# @lc app=leetcode id=993 lang=python3
#
# [993] Cousins in Binary Tree
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        results = []

        def dfs(node, parent, depth):
            if not node:
                return (None, None, 0)
            if node.val==x or node.val==y:
                results.append((parent,depth))
            dfs(node.left, node, depth+1)
            dfs(node.right, node, depth+1)

        dfs(root, None, 0)

        x,y = results

        return x[0]!=y[0] and x[1]==y[1]

# @lc code=end

