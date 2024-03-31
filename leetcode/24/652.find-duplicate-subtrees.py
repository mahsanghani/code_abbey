#
# @lc app=leetcode id=652 lang=python3
#
# [652] Find Duplicate Subtrees
#
# @lc code=start
# Definition for a binary tree node.
import collections
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        sub = collections.defaultdict(list)

        def dfs(node):
            if not node:
                return "null"
            s = ','.join([str(node.val), dfs(node.left), dfs(node.right)])
            if len(sub[s])==1:
                results.append(node)
            sub[s].append(node)
            return s

        results = []
        dfs(root)
        return results

# @lc code=end

