#
# @lc app=leetcode id=1143 lang=python3
#
# [1143] Longest Common Subsequence
#
# @lc code=start
class Solution:
    def longestCommonSubsequence(self, t1: str, t2: str) -> int:
        grid = [[0]*(len(t2)+1) for _ in range(len(t1)+1)]

        for col in reversed(range(len(t2))):
            for row in reversed(range(len(t1))):
                if t2[col]==t1[row]:
                    grid[row][col] = 1+grid[row+1][col+1]
                else:
                    grid[row][col] = max(grid[row+1][col], grid[row][col+1])

        return grid[0][0]
# @lc code=end
    