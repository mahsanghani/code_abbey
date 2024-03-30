#
# @lc app=leetcode id=450 lang=python3
#
# [450] Delete Node in a BST
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def deleteNode(self, node: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not node:
            return node

        if val>node.val:
            node.right = self.deleteNode(node.right,val)
        elif val<node.val:
            node.left = self.deleteNode(node.left,val)
        else:
            if not node.left:
                return node.right
            elif not node.right:
                return node.left
                
            curr = node.right
            while curr.left:
                curr = curr.left
            node.val = curr.val
            node.right = self.deleteNode(node.right,node.val)
        return node
# @lc code=end

