#
# @lc app=leetcode id=105 lang=python3
#
# [105] Construct Binary Tree from Preorder and Inorder Traversal
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        idx = {}
        for k,v in enumerate(inorder):
            idx[v] = k

        def dfs(l,r):
            if l>r:
                return None

            val = preorder.pop()
            node = TreeNode(val)
            i = idx[val]

            node.left = dfs(l,i-1)
            node.right = dfs(i+1,r)
            return node

        return dfs(0,len(inorder)-1)
# @lc code=end

