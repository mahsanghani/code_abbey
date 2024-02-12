#
# @lc app=leetcode id=1704 lang=python3
#
# [1704] Determine if String Halves Are Alike
#

# @lc code=start
class Solution:
    def countVowels(self, s: str) -> int:
        count = 0
        vowels = "aeiouAEIOU"

        for c in s:
            if c in vowels:
                count += 1

        return count

    def halvesAreAlike(self, s: str) -> bool:
        return self.countVowels(s[:len(s)//2])==self.countVowels(s[len(s)//2:])        

# @lc code=end

