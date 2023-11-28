#
# @lc app=leetcode id=1313 lang=python3
#
# [1313] Decompress Run-Length Encoded List
#

# @lc code=start
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        results = []
        for i in range(0,len(nums),2):
            freq = nums[i]
            val = nums[i+1] if i+1<len(nums) else None
            for j in range(freq):
                results.append(val)
        return results
# @lc code=end

