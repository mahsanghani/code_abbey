#
# @lc app=leetcode id=776 lang=python3
#
# [776] Split BST
#
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def splitBST(self, root: Optional[TreeNode], target: int) -> List[Optional[TreeNode]]:
        results = []

        def dfs(node):

            if not node:
                return [None, None]
            
            if node.val > target:
                left, right = dfs(node.left)
                node.left = right
                return [left, node]
            else:
                left, right = dfs(node.right)
                node.right = left
                return [node, right]
            
        return dfs(root)
# @lc code=end

