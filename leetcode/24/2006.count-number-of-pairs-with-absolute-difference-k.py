#
# @lc app=leetcode id=2006 lang=python3
#
# [2006] Count Number of Pairs With Absolute Difference K
#

# @lc code=start
class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        results = 0
        for i in nums:
            for j in nums:
                if i-j==k:
                    results+=1
        return results
# @lc code=end

