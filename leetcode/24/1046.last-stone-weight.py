#
# @lc app=leetcode id=1046 lang=python3
#
# [1046] Last Stone Weight
#
# @lc code=start
import heapq
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-s for s in stones]
        heapq.heapify(stones)

        while len(stones)>1:
            x = heapq.heappop(stones)
            y = heapq.heappop(stones)
            heapq.heappush(stones,x-y)

        return abs(stones[0]) if stones else 0
# @lc code=end

