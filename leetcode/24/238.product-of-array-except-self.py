#
# @lc app=leetcode id=238 lang=python3
#
# [238] Product of Array Except Self
#

# @lc code=start
import math
from collections import defaultdict
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        results = []
        products = defaultdict(int)
        for j,k in enumerate(nums):
            if k not in products:
                products[k] = math.prod([x for i,x in enumerate(nums) if i!=j])
            results.append(products[k])
        return results
# @lc code=end

