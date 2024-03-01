#
# @lc app=leetcode id=49 lang=python3
#
# [49] Group Anagrams
#
# @lc code=start
from collections import defaultdict
class Solution:
    def groupAnagrams(self, words: List[str]) -> List[List[str]]:
        results = defaultdict(list)
        for word in words:
            results[''.join(sorted(word))].append(word)
        return sorted(results.values())
# @lc code=end

