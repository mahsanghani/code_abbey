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
        pairs.sort(key=lambda x:-x[1])

        heap = [x[0] for x in pairs[:k]]
        ksum = sum(heap)
        heapq.heapify(heap)
        results = ksum*pairs[k-1][1]

        for i in range(k, len(nums1)):
            ksum -= heapq.heappop(heap)
            ksum += pairs[i][0]
            heapq.heappush(heap, pairs[i][0])
            results = max(results, ksum*pairs[i][1])

        return results
    
# @lc code=end