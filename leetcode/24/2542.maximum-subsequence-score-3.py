#
# @lc app=leetcode id=2542 lang=python3
#
# [2542] Maximum Subsequence Score
#
# @lc code=start
import heapq
class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        pairs = [(i,j) for i,j in zip(nums1,nums2)]
        pairs = sorted(pairs, key=lambda x:x[1], reverse=True)

        res = 0
        n1s = 0
        heap = []

        for x,y in pairs:
            n1s += x
            heapq.heappush(heap, x)

            if len(heap)>k:
                n1p = heapq.heappop(heap)
                n1s -= n1p
            if len(heap)==k:
                res = max(res, n1s*y)

        return res
# @lc code=end