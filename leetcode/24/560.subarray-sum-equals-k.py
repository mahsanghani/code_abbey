#
# @lc app=leetcode id=560 lang=python3
#
# [560] Subarray Sum Equals K
#
# @lc code=start
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        results = 0
        current = 0
        prefix = {0:1}

        for num in nums:
            current += num
            diff = current-k
            results+=prefix.get(diff,0)
            prefix[current] = 1+prefix.get(current,0)

        return results
# @lc code=end

