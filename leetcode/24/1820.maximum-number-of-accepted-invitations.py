#
# @lc app=leetcode id=1820 lang=python3
#
# [1820] Maximum Number of Accepted Invitations
#
# @lc code=start
from collections import defaultdict

class Solution:
    def maximumInvitations(self, grid):
        rows = len(grid)
        cols = len(grid[0])
        kids = defaultdict(int)

        def dfs(boy, visit):
            return False

        for boy in range(rows):
            dfs(boy,set())

        return len(kids)
# @lc code=end
