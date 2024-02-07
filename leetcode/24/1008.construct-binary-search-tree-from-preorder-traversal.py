#
# @lc app=leetcode id=1008 lang=python3
#
# [1008] Construct Binary Search Tree from Preorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        if not preorder:
            return None

        node = preorder[0]
        root = TreeNode(node)
        low = [i for i in preorder if i<node]
        high = [i for i in preorder if i>node]

        root.left = self.bstFromPreorder(low)
        root.right = self.bstFromPreorder(high)

        return root
# @lc code=end

