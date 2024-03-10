#
# @lc app=leetcode id=2542 lang=python3
#
# [2542] Maximum Subsequence Score
#
# @lc code=start
import heapq
class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        res,pfx,heap = 0,0,[]

        for i,j in sorted(list(zip(nums1,nums2)), key=itemgetter(1), reverse=True):
            pfx += i
            heapq.heappush(heap, i)
            if len(heap)==k:
                res = max(res, pfx*j)
                pfx -= heapq.heappop(heap)

        return res
# @lc code=end