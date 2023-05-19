#
# @lc app=leetcode id=912 lang=python3
#
# [912] Sort an Array
#

# @lc code=start
from queue import PriorityQueue as pq
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        q = pq()
        for i in nums: q.put(i)
        for i in range(len(nums)): nums[i] = q.get()
        return nums
# @lc code=end

