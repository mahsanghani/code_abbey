#
# @lc app=leetcode id=1512 lang=python3
#
# [1512] Number of Good Pairs
#

# @lc code=start
from collections import Counter
class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        results = 0
        counter = Counter(nums)
        for k,v in counter.items():
            results += ((v*(v-1))/2)
        return int(results)
# @lc code=end

