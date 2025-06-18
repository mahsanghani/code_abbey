# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        cols = defaultdict(list)
        que = deque([(root, 0)])

        while que:
            node, pos = que.popleft()
            if node:
                cols[pos].append(node.val)
                que.append((node.left, pos-1))
                que.append((node.right, pos+1))

        return [cols[x] for x in sorted(cols)]
    