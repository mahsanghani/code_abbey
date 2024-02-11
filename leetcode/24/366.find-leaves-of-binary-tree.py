#
# @lc app=leetcode id=366 lang=python3
#
# [366] Find Leaves of Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        # depth = 0
        results = []

        def height(node):
            if not node:
                return None
            depth = 1+max(height(node.left), height(node.right))
            if height==len(depth):
                results.append([])
            results[depth].append(node.val)
            return depth

        return results
# @lc code=end

