#
# @lc app=leetcode id=438 lang=python3
#
# [438] Find All Anagrams in a String
#

# @lc code=start
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        cp = Counter(p)
        results = []
        for i in range(len(s)-len(p)+1):
            if Counter(s[i:i+len(p)])==cp:
                results.append(i)
        return results
# @lc code=end

