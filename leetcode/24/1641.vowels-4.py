#
# @lc app=leetcode id=1641 lang=python3
#
# [1641] Count Sorted Vowel Strings
#

# @lc code=start
class Solution:
    def countVowelStrings(self, n: int) -> int:
        dp = [[0]*6]*(n+1)
        for i in range(1,6):
            dp[1][i] = i
        for j in range(2,n+1):
            dp[j][1] = 1
            for k in range(2,6):
                dp[j][k] = dp[j][k-1]+dp[j-1][k]
        return dp[n][5]
# @lc code=end

