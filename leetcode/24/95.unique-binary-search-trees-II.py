#
# @lc app=leetcode id=95 lang=python3
#
# [95] Unique Binary Search Trees II
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        dp = {}
        res = []
        def dfs(l,r):
            if l>r:
                return [None]
            if (l,r) in dp:
                return dp[(l,r)]

            results = []

            for val in range(l,r+1):
                for left in dfs(l,val-1):
                    for right in dfs(val+1,r):
                        node = TreeNode(val,left,right)
                        results.append(node)
            dp[(l,r)] = results
            return results

        return dfs(1,n)
# @lc code=end

