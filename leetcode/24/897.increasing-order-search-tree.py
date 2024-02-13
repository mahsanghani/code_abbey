#
# @lc app=leetcode id=897 lang=python3
#
# [897] Increasing Order Search Tree
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        results = []

        def dfs(node):
            if not node:
                return None
            
            dfs(node.left)
            results.append(node.val)
            dfs(node.right)

        def array2BST(arr):
            if not arr:
                return None
            
            node = TreeNode(arr[0])
            node.right = array2BST(arr[1:])

            return node
        
        dfs(root)
        return array2BST(results)

# @lc code=end

