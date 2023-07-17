#
# @lc app=leetcode id=219 lang=python3
#
# [219] Contains Duplicate II
#

# @lc code=start
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hashdict = {}

        for idx, num in enumerate(nums):
            if num in hashdict and abs(idx - hashdict[num]) <= k:
                return True
            hashdict[num] = idx
        
        return False
# @lc code=end

