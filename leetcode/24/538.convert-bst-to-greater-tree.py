#
# @lc app=leetcode id=538 lang=python3
#
# [538] Convert BST to Greater Tree
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    val = 0
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root:
            if root.right: self.convertBST(root.right)
            root.val = self.val = self.val + root.val
            if root.left: self.convertBST(root.left)
            return root
        
class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        curSum = 0

        def dfs(node):
            if not node:
                return node
            nonlocal curSum
            dfs(node.right)
            temp = node.val
            node.val += curSum
            curSum += temp
            dfs(node.left)
        
        dfs(root)
        return root
    
class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        curr = 0

        def dfs(node):
            if not node:
                return None
            nonlocal curr
            dfs(node.right)
            curr, node.val = curr+node.val, curr+node.val
            dfs(node.left)

        dfs(root)
        return root
# @lc code=end

