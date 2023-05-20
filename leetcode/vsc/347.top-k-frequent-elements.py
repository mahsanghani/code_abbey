#
# @lc app=leetcode id=347 lang=python3
#
# [347] Top K Frequent Elements
#

# @lc code=start
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d=Counter(nums)
        print(d)
        d=dict(sorted(d.items(),key=lambda k: k[1],reverse=True))
        print(list(d.keys()))
        return list(d.keys())[:k]
# @lc code=end

