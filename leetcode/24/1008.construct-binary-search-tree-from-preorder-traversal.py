#
# @lc app=leetcode id=1008 lang=python3
#
# [1008] Construct Binary Search Tree from Preorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        def helper(lower=float('-inf'), upper=float('inf')):
            nonlocal idx
            if idx==n:
                return None
            
            val = preorder[idx]
            if val<lower or val>upper:
                return None
            
            idx+=1
            root = TreeNode(val)
            root.left = helper(lower,val)
            root.right = helper(val,upper)
            return root
        
        idx=0
        n=len(preorder)
        return helper()
# @lc code=end

