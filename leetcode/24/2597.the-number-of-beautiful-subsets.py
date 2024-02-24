#
# @lc app=leetcode id=2597 lang=python3
#
# [2597] The Number of Beautiful Subsets
#
# @lc code=start
from collections import Counter, defaultdict
class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        n = len(nums)
        results = 0

        def dfs(i, ctr):
            nonlocal results
            if i == n:
                if ctr:
                    results += 1
                return
            # if one less and one more not in counter
            if nums[i]-k not in ctr and nums[i]+k not in ctr:
                ctr[nums[i]] += 1
                dfs(i+1,ctr)
                ctr[nums[i]] -= 1
                if not ctr[nums[i]]:
                    del ctr[nums[i]]
            dfs(i+1,ctr)

        dfs(0, Counter())
        return results
# @lc code=end

