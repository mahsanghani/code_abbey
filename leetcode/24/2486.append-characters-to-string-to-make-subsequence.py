#
# @lc app=leetcode id=2486 lang=python3
#
# [2486] Append Characters to String to Make Subsequence
#

# @lc code=start
class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        i,n = 0,len(t)
        for c in s:
            if i<n and t[i]==c:
                i+=1
        return n-i
# @lc code=end

