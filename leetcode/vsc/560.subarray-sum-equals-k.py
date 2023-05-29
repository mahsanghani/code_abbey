#
# @lc app=leetcode id=560 lang=python3
#
# [560] Subarray Sum Equals K
#

# @lc code=start
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res, cur, pre = 0, 0, {0:1}

        for num in nums:
            cur += num
            diff = cur - k
            res += pre.get(diff, 0)
            pre[cur] = 1 + pre.get(cur, 0)

        return res
# @lc code=end

