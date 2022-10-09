# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        # root
        # left
        # right
        # with
        # without
        # max

        def dfs(root):
            if not root:
                return [0, 0]

            left = dfs(root.left)
            right = dfs(root.right)

            with_ = root.val + left[1] + right[1]
            without = max(left) + max(right)

            return [with_, without]

        return max(dfs(root))
