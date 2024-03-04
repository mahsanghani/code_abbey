#
# @lc app=leetcode id=1985 lang=python3
#
# [1985] Find the Kth Largest Integer in the Array
#
# @lc code=start
import heapq
class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        nums = [-int(num) for num in nums]
        heapq.heapify(nums)
        while k>1:
            heapq.heappop(nums)
            k-=1
        return str(-nums[0])
# @lc code=end

