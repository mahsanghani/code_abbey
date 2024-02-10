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
    def balanceBST(self, root: TreeNode) -> TreeNode:
        results = []

        def dfs(node):
            if not node:
                return []
            
            dfs(node.left)
            results.append(node.val)
            dfs(node.right)

        def sortedArraytoBST(nums):
            if not nums:
                return None
            
            mid = len(nums)//2
            root = TreeNode(nums[mid])
            root.left = sortedArraytoBST(nums[:mid])
            root.right = sortedArraytoBST(nums[mid+1:])

            return root
        
        dfs(root)
        return sortedArraytoBST(results) 
# @lc code=end

