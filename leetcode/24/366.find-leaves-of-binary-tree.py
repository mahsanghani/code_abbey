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
        results = []

        return results

    def height(self, node):
        if not node:
            return -1
        
# @lc code=end

