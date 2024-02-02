#
# @lc app=leetcode id=1684 lang=python3
#
# [1684] Count the Number of Consistent Strings
#

# @lc code=start
class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        total = 0
        for word in words:
            if set(word).issubset(set(allowed)):
                total += 1
        return total
# @lc code=end

