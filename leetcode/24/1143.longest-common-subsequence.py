#
# @lc app=leetcode id=1143 lang=python3
#
# [1143] Longest Common Subsequence
#
# @lc code=start
class Solution:
    def longestCommonSubsequence(self, t1: str, t2: str) -> int:
        if len(t1)<len(t2):
            t1,t2=t2,t1

        previous = [0]*(len(t1)+1)
        current = [0]*(len(t1)+1)

        for col in reversed(range(len(t2))):
            for row in reversed(range(len(t1))):
                if t2[col]==t1[row]:
                    current[row]=1+previous[row+1]
                else:
                    current[row] = max(previous[row], current[row+1])
            previous,current = current,previous

        return previous[0]
# @lc code=end
    