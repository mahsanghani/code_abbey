#
# @lc app=leetcode id=1859 lang=python3
#
# [1859] Sorting the Sentence
#

# @lc code=start
class Solution:
    def sortSentence(self, s: str) -> str:
        results = [""] * len(s.split(" "))
        for word in s.split(" "):
            results[int(word[-1])-1] = word[:-1]
        return " ".join(results)
# @lc code=end

