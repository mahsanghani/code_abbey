# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        dp = {}

        def bt(n):
            if n == 0:
                return []
            if n == 1:
                return [TreeNode()]
            if n in dp:
                return dp[n]
            results = []
            for l in range(n):
                r = n - 1 - l
                left = bt(l)
                right = bt(r)

                for t1 in left:
                    for t2 in right:
                        results.append(TreeNode(0, t1, t2))
            dp[n] = results
            return results

        return bt(n)
