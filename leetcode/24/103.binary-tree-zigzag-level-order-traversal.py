#
# @lc app=leetcode id=103 lang=python3
#
# [103] Binary Tree Zigzag Level Order Traversal
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        rev = 1
        queue = deque([root] if root else [])

        while queue:
            lev = []
            for _ in range(len(queue)):
                node = queue.popleft()
                lev.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            if rev==1:
                res.append(lev)
            else:
                res.append(lev[::-1])
            rev=-rev
        return res
# @lc code=end

