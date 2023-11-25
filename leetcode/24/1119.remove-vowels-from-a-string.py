#
# @lc app=leetcode id=1119 lang=python3
#
# [1119] Remove Vowels from a String
#

# @lc code=start
class Solution:
    def removeVowels(self, s: str) -> str:
        mapping = str.maketrans({'a':'', 'e':'', 'i':'', 'o':'', 'u':''})
        return s.translate(mapping)
# @lc code=end

