#
# @lc app=leetcode id=662 lang=python3
#
# [662] Maximum Width of Binary Tree
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        table = {}
        width = 0

        def dfs(node,depth,col):
            if not node:
                return node

            nonlocal width
            
            if depth not in table:
                table[depth] = col

            width = max(width, col-table[depth]+1)
            
            dfs(node.left, depth+1, 2*col)
            dfs(node.right, depth+1, 2*col+1)

        dfs(root,0,0)
        return width
# @lc code=end

