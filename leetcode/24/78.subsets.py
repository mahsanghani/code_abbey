#
# @lc app=leetcode id=78 lang=python3
#
# [78] Subsets
#

# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def bt(first=0, curr=[]):
            if len(curr)==k:
                results.append(curr[:])
                return
            for i in range(first, n):
                curr.append(nums[i])
                bt(i+1,curr)
                curr.pop()
            
        results = []
        n = len(nums)
        for k in range(n+1):
            bt()
        return results
# @lc code=end

