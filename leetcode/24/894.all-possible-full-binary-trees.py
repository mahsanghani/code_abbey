#
# @lc app=leetcode id=894 lang=python3
#
# [894] All Possible Full Binary Trees
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        if n%2==0:
            return []
        if n==1:
            return [TreeNode()]

        results = []

        for i in range(1,n,2):
            left = self.allPossibleFBT(i)
            right = self.allPossibleFBT(n-i-1)

            for l in left:
                for r in right:
                    root = TreeNode(0,l,r)
                    results.append(root)

        return results

# @lc code=end

