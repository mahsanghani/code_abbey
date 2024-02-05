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
            if not node:
                return True
            if node.left not in [2,3]:
                dfs(node.left)
            if node.right not in [2,3]:
                dfs(node.right)
            if node.val == 2:
                print(node.left.val or node.right.val)
                return (node.left.val or node.right.val)
            if node.val == 3:
                print(node.left.val and node.right.val)
                return (node.left.val and node.right.val)
            return True
        dfs(root)
# @lc code=end

