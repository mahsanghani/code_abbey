#
# @lc app=leetcode id=49 lang=python3
#
# [49] Group Anagrams
#
# @lc code=start
from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        results = defaultdict(list)

        for s in strs:
            results[''.join(sorted(s))].append(s)

        return sorted(results.values())
# @lc code=end

