#
# @lc app=leetcode id=337 lang=python3
#
# [337] House Robber III
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        # [with_root, without_root]

        def dfs(node):
            if not node:
                return [0,0]

            left = dfs(node.left)
            right = dfs(node.right)

            with_ = node.val + left[1] + right[1]
            without = max(left) + max(right)

            return [with_, without]

        return max(dfs(root))
# @lc code=end

