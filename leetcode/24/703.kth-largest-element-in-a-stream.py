#
# @lc app=leetcode id=703 lang=python3
#
# [703] Kth Largest Element in a Stream
#
# @lc code=start
import heapq
class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.k = self.k
        self.nums = heapq.heapify(nums)
        while len(self.nums)>self.k:
            heapq.heappop(self.nums)

    def add(self, val: int) -> int:
        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
# @lc code=end

