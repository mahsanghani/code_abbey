#
# @lc app=leetcode id=392 lang=python3
#
# [392] Is Subsequence
#

# @lc code=start
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i,j = 0,0
        for i in range(len(s)):
            if i<len(s) and j<len(t):
                if s[i]==t[j]:
                    i+=1
                j+=1
        return True if i==len(s) else False
        
# @lc code=end

