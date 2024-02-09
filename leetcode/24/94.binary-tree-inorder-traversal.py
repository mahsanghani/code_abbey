#
# @lc app=leetcode id=94 lang=python3
#
# [94] Binary Tree Inorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        results = []
        
        def dfs(node):
            if not node:
                return None
            dfs(node.left)
            results.append(node.val)
            dfs(node.right)
            
        dfs(root)
        return results
# @lc code=end

