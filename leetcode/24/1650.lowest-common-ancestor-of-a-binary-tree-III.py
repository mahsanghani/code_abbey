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
        d = 0
        while p:
            p = p.parent
            d += 1
            return d

    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        return p
# @lc code=end

