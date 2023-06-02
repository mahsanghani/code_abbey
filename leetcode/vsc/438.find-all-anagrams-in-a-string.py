#
# @lc app=leetcode id=438 lang=python3
#
# [438] Find All Anagrams in a String
#

# @lc code=start
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(p)>len(s):
            return []
        
        cp = {}
        cs = {}

        for i in range(len(p)):
            cp[p[i]] = 1 + cp.get(p[i], 0)
            cs[s[i]] = 1 + cs.get(s[i], 0)
        
        results = [0] if cs == cp else []
        l = 0
        for j in range(len(p), len(s)):
            cs[s[j]] = 1 + cs.get(s[j], 0)
            cs[s[l]] -= 1

            if cs[s[l]] == 0:
                cs.pop(s[l])
            l += 1
            if cs == cp:
                results.append(l)

        return results
# @lc code=end

