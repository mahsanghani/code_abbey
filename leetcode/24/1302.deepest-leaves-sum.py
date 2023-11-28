#
# @lc app=leetcode id=1302 lang=python3
#
# [1302] Deepest Leaves Sum
#

# @lc code=start
# Definition for a binary tree node.
from collections import deque
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        depth = 0
        deepest = 0

        def dfs(node, level):
            nonlocal depth
            nonlocal deepest

            if not node:
                return
            
            if level==depth:
                deepest += node.val
            elif level>depth:
                depth = level
                deepest = node.val
            
            dfs(node.left, level+1)
            dfs(node.right, level+1)

        dfs(root, 0)
        return deepest
# @lc code=end

