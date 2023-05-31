#
# @lc app=leetcode id=1930 lang=python3
#
# [1930] Unique Length-3 Palindromic Subsequences
#

# @lc code=start
class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        right = Counter(s)
        res, left = set(), set()

        for i in range(len(s)):
            right[s[i]] -= 1
            if right[s[i]] == 0:
                right.pop(s[i])

            for j in range(26):
                c = chr(ord("a") + j)
                if c in left and c in right:
                    res.add((s[i], c))

            left.add(s[i])

        return len(res)
        
# @lc code=end

