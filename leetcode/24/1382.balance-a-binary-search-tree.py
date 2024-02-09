#
# @lc app=leetcode id=1382 lang=python3
#
# [1382] Balance a Binary Search Tree
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def dfs(node):
        if not node:
            return None
        
        mid = len(node)//2
        root = TreeNode(node[mid])
        root.left = self.dfs(node[:mid])
        root.right = self.dfs(node[mid+1:])
        
        return root

    def balanceBST(self, root: TreeNode) -> TreeNode:
        results = []
        if root:
            self.balanceBST(root.left)
            results.append(root.val)
            self.balanceBST(root.right)

        # return results
        
# @lc code=end

