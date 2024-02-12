#
# @lc app=leetcode id=1650 lang=python3
#
# [1650] Lowest Common Ancestor of a Binary Search Tree III
#

# @lc code=start
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None

class Solution:
    def depth(self, p):
        if not p:
            return -1
        return 1 + self.depth(p.parent)

    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        p_d = self.depth(p)
        q_d = self.depth(q)

        while p_d > q_d:
            p = p.parent
            p_d -= 1

        while q_d > p_d:
            q = q.parent
            q_d -= 1

        while p != q:
            p = p.parent
            q = q.parent

        return p
# @lc code=end

