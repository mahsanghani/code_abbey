#
# @lc app=leetcode id=76 lang=python3
#
# [76] Minimum Window Substring
#

# @lc code=start
from collections import Counter
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "":
            return ""
        
        l = 0
        countT = {}
        window = {}

        for c in t:
            countT[c] = countT.get(c,0) + 1

        have = 0
        need = len(countT)
        res = [-1,-1]
        resLen = float("infinity")

        for r in range(len(s)):
            c = s[r]
            window[c] = window.get(c, 0) + 1
        
            if c in countT and window[c] == countT[c]:
                have += 1
            
            while have == need:
                if (r-l+1) < resLen:
                    res = [l,r]
                    resLen = r-l+1
                window[s[l]] -= 1
                if s[l] in countT and window[s[l]] < countT[s[l]]:
                    have -= 1
                l += 1

        l,r = res
        print(resLen)
        return s[l:r+1] if resLen != float("infinity") else ""

# @lc code=end

