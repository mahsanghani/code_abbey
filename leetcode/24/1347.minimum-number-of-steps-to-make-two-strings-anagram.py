#
# @lc app=leetcode id=1347 lang=python3
#
# [1347] Minimum Number of Steps to Make Two Strings Anagram
#

# @lc code=start
from collections import Counter
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        return sum((Counter(s)-Counter(t)).values())
# @lc code=end

