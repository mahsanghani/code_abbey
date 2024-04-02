#
# @lc app=leetcode id=513 lang=python3
#
# [513] Find Bottom Left Tree Value
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        queue = deque([root])

        while queue:
            node = queue.popleft()
            if node.right:
                queue.append(node.right)
            if node.left:
                queue.append(node.left)
        return node.val

class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        depth = -1
        leftval = 0

        def dfs(node, d):
            if not node:
                return node

            nonlocal depth
            nonlocal leftval

            if d > depth:
                depth = d
                leftval = node.val

            dfs(node.left, d+1)
            dfs(node.right, d+1)

        dfs(root, 0)
        return leftval
# @lc code=end

