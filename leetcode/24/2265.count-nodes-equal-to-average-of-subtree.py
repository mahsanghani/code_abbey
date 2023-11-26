#
# @lc app=leetcode id=2265 lang=python3
#
# [2265] Count Nodes Equal to Average of Subtree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        def count(node):
            if not node:
                return 0,0
            
            ls, lc = count(node.left)
            rs, rc = count(node.right)

            ts = ls + rs + node.val
            tc = lc + rc + 1

            return ts, tc
            
        def rec_avg(node):
            if not node:
                return 0
            
            sub_sum, sub_count = count(node)
            return sub_sum / sub_count
        
        return rec_avg(root)
# @lc code=end

