#
# @lc app=leetcode id=98 lang=python3
#
# [98] Validate Binary Search Tree
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        # recursive + valid range approach
        def validate(node, low=float("-inf"), high=float("inf")):
            if not node:  # empty tree is valid BST 
                return True

            if node.val <= low or node.val >= high:
                return False
            # check left and right node
            return (validate(node.right, node.val, high) and
                    validate(node.left, low, high=node.val))
        return validate(root)
        
# @lc code=end

