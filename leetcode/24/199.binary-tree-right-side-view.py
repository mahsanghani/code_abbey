#
# @lc app=leetcode id=199 lang=python3
#
# [199] Binary Tree Right Side View
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        results = []
        queue = deque([root])

        while queue:
            right = None
            n = len(queue)
            for _ in range(n):
                node = queue.popleft()
                if node:
                    right = node
                    queue.append(node.left)
                    queue.append(node.right)

            if right:
                results.append(right.val)

        return results
# @lc code=end

