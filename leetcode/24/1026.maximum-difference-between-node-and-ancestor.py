#
# @lc app=leetcode id=1026 lang=python3
#
# [1026] Maximum Difference Between Node and Ancestor
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        def dfs(node, _max, _min):
            if not node:
                return _max-_min
            
            _max = max(_max, node.val)
            _min = min(_min, node.val)
            left = dfs(node.left, _max, _min)
            right = dfs(node.right, _max, _min)

            return max(left, right)
        
        return dfs(root, root.val, root.val)
# @lc code=end

