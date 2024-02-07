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
        def helper(in_left=0, in_right=len(preorder)):
            nonlocal pre_idx
            if in_left==in_right:
                return None
            root_val = preorder[pre_idx]
            root = TreeNode(root_val)
            index = idx_map[root_val]

            pre_idx+=1
            root.left = helper(in_left, index)
            root.right = helper(index+1, in_right)
            return root
        
        inorder = sorted(preorder)
        pre_idx = 0
        idx_map = {val:idx for idx, val in enumerate(inorder)}
        return helper()
# @lc code=end

