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
        max_depth = -1
        bot_left_val = 0

        def dfs(node, depth):
            if not node:
                return node

            nonlocal max_depth
            nonlocal bot_left_val

            if depth > max_depth:
                max_depth = depth
                bot_left_val = node.val

            dfs(node.left, depth+1)
            dfs(node.right, depth+1)

        dfs(root, 0)
        return bot_left_val
# @lc code=end

