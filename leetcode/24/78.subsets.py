#
# @lc app=leetcode id=78 lang=python3
#
# [78] Subsets
#

# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        results = []
        n = len(nums)

        for i in range(2**n, 2**(n+1)):
            bitmask = bin(i)[3:]
            results.append([nums[j] for j in range(n) if bitmask[j]=='1'])
        
        return results
# @lc code=end

