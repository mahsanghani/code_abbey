#
# @lc app=leetcode id=1641 lang=python3
#
# [1641] Count Sorted Vowel Strings
#

# @lc code=start
class Solution:
    def countVowelStrings(self, n: int) -> int:
        memo = [[0]*6]*(n+1)
        return self.dp(n,5,memo)

    def dp(self, n, v, memo):
        if n==1:
            return v
        if v==1:
            return 1
        if memo[n][v]!=0:
            return memo[n][v]
        results = self.dp(n-1,v,memo) + self.dp(n,v-1,memo)
        memo[n][v] = results
        return results

# @lc code=end

