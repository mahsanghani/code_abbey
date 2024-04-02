#
# @lc app=leetcode id=124 lang=python3
#
# [124] Binary Tree Maximum Path Sum
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        results = []
        results.append(root.val)

        def dfs(node):
            if not node:
                return 0

            left = dfs(node.left)
            right = dfs(node.right)
            left = max(left,0)
            right = max(right,0)

            results[0] = max(results[0], node.val + left + right)

            return node.val + max(left,right)

        dfs(root)
        return results[0]
# @lc code=end

