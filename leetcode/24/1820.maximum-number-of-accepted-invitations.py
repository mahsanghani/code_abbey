#
# @lc app=leetcode id=1820 lang=python3
#
# [1820] Maximum Number of Accepted Invitations
#
# @lc code=start
from collections import defaultdict

class Solution:
    def maximumInvitations(self, grid):
        boys = len(grid)
        girls = len(grid[0])
        kids = defaultdict(int)

        def dfs(boy, visit):
            for girl in range(girls):
                if grid[boy][girl] and girl not in visit:
                    visit.add(girl)

                    if girl not in kids or dfs(kids[girl],visit):
                        kids[girl] = boy
                        return True
                    
            return False

        for boy in range(boys):
            dfs(boy,set())

        return len(kids)
# @lc code=end
