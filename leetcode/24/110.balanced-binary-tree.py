#
# @lc app=leetcode id=110 lang=python3
#
# [110] Balanced Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def dfs(root):
            if not root:
                return [True, 0]
            
            left = dfs(root.left)
            right = dfs(root.right)
            balanced = (left[0] and right[0] and abs(left[1]-right[1]) <= 1)

            return [balanced, 1+max(left[1], right[1])]
        
        return dfs(root)[0]
# @lc code=end

