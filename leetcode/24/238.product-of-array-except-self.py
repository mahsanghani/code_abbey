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
        for i,j in enumerate(nums):
            if j not in products:
                products[j] = math.prod([x for k,x in enumerate(nums) if k!=i])
            results.append(products[j])
        return results
# @lc code=end

