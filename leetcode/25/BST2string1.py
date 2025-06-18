# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        results = []

        def dfs(node):
            if not node:
                return ''

            results.append('(')
            results.append(str(node.val))
            if not node.left and node.right:
                results.append('()')
            dfs(node.left)
            dfs(node.right)
            results.append(')')

        dfs(root)
        return ''.join(results[1:-1])
    