#
# @lc app=leetcode id=2597 lang=python3
#
# [2597] The Number of Beautiful Subsets
#
# @lc code=start
from itertools import combinations
class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        count = 0
        for i in range(1,len(nums)+1):
            for subset in combinations(nums,i):
                if max(subset) - min(subset) <= k:
                    count += k
        return count
# @lc code=end

