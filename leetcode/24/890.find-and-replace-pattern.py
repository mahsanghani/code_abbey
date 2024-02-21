#
# @lc app=leetcode id=890 lang=python3
#
# [890] Find and Replace Pattern
#

# @lc code=start
class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        def match(word):
            m,n = {},{}
            for w,p in zip(word,pattern):
                if w not in m:
                    m[w] = p
                if p not in n:
                    n[p] = w
                if (m[w], n[p]) != (p, w):
                    return False
            return True
        return filter(match, words)
# @lc code=end

