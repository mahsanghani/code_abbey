# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []

        if not root:
            return res

        cols = defaultdict(list)
        minCol = 0
        maxCol = 0
        
        def dfs(node, row, col):
            nonlocal minCol, maxCol

            if not node:
                return

            cols[col].append((row, node.val))

            minCol = min(minCol, col)
            maxCol = max(maxCol, col)

            dfs(node.left, row+1, col-1)
            dfs(node.right, row+1, col+1)
            
        dfs(root,0,0)
        
        for col in range(minCol, maxCol+1):
            col_vals = sorted(cols[col], key=lambda x: x[0])
            res.append([val for key, val in col_vals])

        return res
    