#
# @lc app=leetcode id=2638 lang=python3
#
# [2638] Count the Number of K-Free Subsets
#
# @lc code=start
from operator import add,mul
from functools import reduce
from collections import defaultdict
class Solution:
    def countTheNumOfKFreeSubsets(self, nums: List[int], k: int) -> int:
        size = defaultdict(int)
        
        for i in sorted(nums):
            size[i] = size[i-k]+1
            size.pop(i-k)

        m = max(size.values())
        fib = [1]*(m+2)
        
        for i in range(2,m+2):
            fib[i] = fib[i-2]+fib[i-1]
        
        return reduce(mul, (fib[v+1] for v in size.values()))
# @lc code=end

