#
# @lc app=leetcode id=98 lang=python3
#
# [98] Validate Binary Search Tree
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def dfs(node,left,right):
            if not node:
                return True
            if not (node.val<right and node.val>left):
                return False

            return (dfs(node.left,left,node.val) and dfs(node.right,node.val,right))

        return dfs(root,float("-inf"),float("inf"))
# @lc code=end

