#
# @lc app=leetcode id=438 lang=python3
#
# [438] Find All Anagrams in a String
#

# @lc code=start
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        start = 0
        results = []
        cp, cs = {}, {}

        for c in p:
            cp[c] = 1 + cp.get(c, 0)

        for i in range(len(s)):
            cs[s[i]] = 1 + cs.get(s[i], 0)

            if i >= len(p) - 1:
                if cs == cp:
                    results.append(start)
            
                if s[start] in cs:
                    cs[s[start]] -= 1
                    if cs[s[start]] == 0:
                        del cs[s[start]]
                start += 1

        return results
# @lc code=end

