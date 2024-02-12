#
# @lc app=leetcode id=1305 lang=python3
#
# [1305] All Elements in Two Binary Search Trees
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        results = []
        def dfs(node):
            if not node:
                return None
            results.append(node.val)
            dfs(node.left)
            dfs(node.right)
        dfs(root1)
        dfs(root2)
        return sorted(results)
# @lc code=end

