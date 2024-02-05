#
# @lc app=leetcode id=2331 lang=python3
#
# [2331] Evaluate Boolean Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        # 0 = False
        # 1 = True
        # 2 = OR
        # 3 = AND
        # DFS in post-order

        def dfs(node):
            if not node.left and not node.right:
                return True if node.val==1 else False
            if node.val == 2:
                return dfs(node.left) or dfs(node.right)
            if node.val == 3:
                return dfs(node.left) and dfs(node.right)
        dfs(root)
# @lc code=end

