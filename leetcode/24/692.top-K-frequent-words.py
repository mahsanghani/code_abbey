#
# @lc app=leetcode id=692 lang=python3
#
# [692] 692. Top K Frequent Words
#
# @lc code=start
import heapq
import collections
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        counts = collections.Counter(words)
        heap = [(-freq,word) for word,freq in counts.items()]
        heapq.heapify(heap)

        return [heapq.heappop(heap)[1] for _ in range(k)]
# @lc code=end

