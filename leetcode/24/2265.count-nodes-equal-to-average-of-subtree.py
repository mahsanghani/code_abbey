#
# @lc app=leetcode id=2265 lang=python3
#
# [2265] Count Nodes Equal to Average of Subtree
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        results = 0
        
        def dfs(node):
            nonlocal results
            if not node:
                return 0,0
            
            ls,lc = dfs(node.left)
            rs,rc = dfs(node.right)

            ts = ls + rs + node.val
            tc = lc + rc + 1

            if ts//tc==node.val:
                results+=1
            return ts,tc
        
        dfs(root)
        return results
# @lc code=end

