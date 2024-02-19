#
# @lc app=leetcode id=1207 lang=python3
#
# [1207] Unique Number of Occurrences
#

# @lc code=start
from collections import Counter
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        counts = Counter(arr)
        return len(set(counts.values()))==len(counts.values())
# @lc code=end

