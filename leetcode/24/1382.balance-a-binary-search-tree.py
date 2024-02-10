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
            
        def sortedArraytoBST(lo, hi):
            if lo>hi:
                return None
            
            mid = (lo+hi)//2
            root = TreeNode(results[mid])
            root.left = sortedArraytoBST(lo,mid-1)
            root.right = sortedArraytoBST(mid+1,hi)

            return root
        
        dfs(root)
        return sortedArraytoBST(0,len(results)-1) 
# @lc code=end

