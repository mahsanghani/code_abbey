#
# @lc app=leetcode id=669 lang=python3
#
# [669] Trim a Binary Search Tree
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def trimBST(self, node: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
        if not node:
            return node

        node.left = self.trimBST(node.left, low, high)
        node.right = self.trimBST(node.right, low, high)

        if node.val > high:
            return self.trimBST(node.left, low, high)
        if node.val < low:
            return self.trimBST(node.right, low, high)

        return node
# @lc code=end

