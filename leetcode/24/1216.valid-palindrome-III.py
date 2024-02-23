#
# @lc app=leetcode id=1216 lang=python3
#
# [1216] Valid Palindrome III
#
# @lc code=start
class Solution:
    def isValidPalindrome(self, s: str, k: int) -> bool:
        memo = [0]*len(s)
        temp,prev = 0,0
        for i in range(len(s)-2,-1,-1):
            prev=0
            for j in range(i+1,len(s)):
                temp=memo[j]
                if s[i]==s[j]:
                    memo[j]=prev
                else:
                    memo[j]=1+min(memo[j],memo[j-1])
                prev=temp
        return memo[-1]<=k
# @lc code=end

