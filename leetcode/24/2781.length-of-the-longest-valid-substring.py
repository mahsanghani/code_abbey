#
# @lc app=leetcode id=2781 lang=python3
#
# [2781] Length of the Longest Valid Substring
#
# @lc code=start
class Solution:
    def longestValidSubstring(self, word: str, forbidden: List[str]) -> int:
        forb = set(forbidden)
        left,results = 0,0

        for i in range(len(word)):
            for j in range(max(left,i-9),i+1):
                if word[j:i+1] in forb:
                    left=j+1
            results = max(results,i+1-left)
        return results
# @lc code=end

