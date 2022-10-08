# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        results = []

        def dfs(root):
            if not root:
                return

            results.append('(')
            results.append(str(root.val))

            if not root.left and root.right:
                results.append("()")
            dfs(root.left)
            dfs(root.right)
            results.append(')')

        dfs(root)
        return ''.join(results)[1:-1]
