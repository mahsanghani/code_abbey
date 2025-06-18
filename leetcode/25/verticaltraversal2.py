# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        cols = defaultdict(list)

        def dfs(node, row, col):
            if not node:
                return
            cols[col].append((row, node.val))
            dfs(node.left, row+1, col-1)
            dfs(node.right, row+1, col+1)
            
        dfs(root,0,0)

        res = []
        
        for col in sorted(cols):
            col_vals = sorted(cols[col], key=lambda x: x[0])
            res.append([val for key, val in col_vals])
        
        return res
