#
# @lc app=leetcode id=347 lang=python3
#
# [347] Top K Frequent Elements
#

# @lc code=start
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        return list(dict(sorted(Counter(nums).items(),key=lambda t:t[1],reverse=True)).keys())[:k]
# @lc code=end

