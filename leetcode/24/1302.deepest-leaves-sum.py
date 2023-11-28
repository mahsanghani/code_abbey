#
# @lc app=leetcode id=1302 lang=python3
#
# [1302] Deepest Leaves Sum
#

# @lc code=start
# Definition for a binary tree node.
from collections import deque
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        q = deque([root])
        current = 0
        while q:
            current = 0
            size = len(q)

            for i in range(size):
                node = q.popleft()
                current += node.val

                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

        return current
# @lc code=end

