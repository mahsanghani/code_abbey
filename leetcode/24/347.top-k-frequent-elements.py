#
# @lc app=leetcode id=347 lang=python3
#
# [347] Top K Frequent Elements
#
# @lc code=start
from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = Counter(nums)
        counts = dict(sorted(counts.items(), key=lambda kv:kv[1], reverse=True))
        return list(counts.keys())[:k]
# @lc code=end

