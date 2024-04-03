#
# @lc app=leetcode id=2641 lang=python3
#
# [2641] Cousins in Binary Tree II
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        m = Counter()

        def dfs(l,r):
            if not r:
                return r
            m[l] += r.val
            dfs(l+1,r.left)
            dfs(l+1,r.right)
        dfs(0,root)

        def dfs2(l,r,curr):
            cousins = m[l+1] - (r.left.val if r.left else 0) - (r.right.val if r.right else 0)
            if r.left:
                curr.left = TreeNode(cousins)
                dfs2(l+1,r.left,curr.left)
            if r.right:
                curr.right = TreeNode(cousins)
                dfs2(l+1,r.right,curr.right)
            return curr

        return dfs2(0,root,TreeNode(0))

# @lc code=end

