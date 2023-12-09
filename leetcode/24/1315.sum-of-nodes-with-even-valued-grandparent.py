#
# @lc app=leetcode id=1315 lang=python3
#
# [1315] Sum of Nodes with Even-Valued Grandparent
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def helper(self, node: TreeNode, parent: int, grandparent: int) -> int:
        if not node:
            return 0
        return self.helper(node.left,node.val,parent) \
            + self.helper(node.right,node.val,parent)\
            + (node.val if grandparent % 2 == 0 else 0)
    
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        return self.helper(root,-1,-1)
# @lc code=end

