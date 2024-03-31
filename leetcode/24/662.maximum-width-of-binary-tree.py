#
# @lc app=leetcode id=662 lang=python3
#
# [662] Maximum Width of Binary Tree
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        res = 0
        prev_num = 1
        prev_level = 0
        queue = deque([[root, prev_num, prev_level]])

        while queue:
            node,num,lvl = queue.popleft()

            if lvl>prev_level:
                prev_level = lvl
                prev_num = num

            res = max(res, num-prev_num+1)
            if node.left:
                queue.append([node.left, 2*num, lvl+1])
            if node.right:
                queue.append([node.right, 2*num+1, lvl+1])
        return res
# @lc code=end

