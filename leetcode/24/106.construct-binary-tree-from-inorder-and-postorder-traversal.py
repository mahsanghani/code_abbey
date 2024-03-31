#
# @lc app=leetcode id=106 lang=python3
#
# [106] Construct Binary Tree from Inorder and Postorder Traversal
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        idx = {}
        for k,v in enumerate(inorder):
            idx[v] = k
    
        def dfs(l,r):
            if l>r:
                return None
                
            val = postorder.pop()
            node = TreeNode(val)
            i = idx[val]
            node.right = dfs(i+1,r)
            node.left = dfs(l,i-1)
            
            return node

        return dfs(0, len(inorder)-1)
# @lc code=end

