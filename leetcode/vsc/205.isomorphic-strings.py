#
# @lc app=leetcode id=205 lang=python3
#
# [205] Isomorphic Strings
#

# @lc code=start
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        ST = {}
        TS = {}

        if len(s)!=len(t):
            return False

        for i in range(len(s)):
            c1 = s[i]
            c2 = t[i]

            if ((c1 in ST and ST[c1]!=c2) or (c2 in TS and TS[c2]!=c1)):
                return False

            ST[c1] = c2
            TS[c2] = c1

        return True
# @lc code=end

