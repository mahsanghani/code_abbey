#
# @lc app=leetcode id=557 lang=python3
#
# [557] Reverse Words in a String III
#

# @lc code=start
class Solution:
    def reverseWords(self, s: str) -> str:
        results = []
        words = s.split(" ")
        for word in words:
            results.append(word[::-1])
        return " ".join(results)
# @lc code=end

