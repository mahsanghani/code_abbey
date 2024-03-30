#
# @lc app=leetcode id=450 lang=python3
#
# [450] 701. Insert into a Binary Search Tree
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def insertIntoBST(self, node: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not node:
            return TreeNode(val)

        if val>node.val:
            node.right = self.insertIntoBST(node.right, val)
        else:
            node.left = self.insertIntoBST(node.left, val)

        return node
# @lc code=end

