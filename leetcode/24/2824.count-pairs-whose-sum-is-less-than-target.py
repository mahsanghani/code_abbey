#
# @lc app=leetcode id=2824 lang=python3
#
# [2824] Count Pairs Whose Sum is Less than Target
#

# @lc code=start
class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        results = 0

        for j in range(1,len(nums)):
            for i in range(0,j):
                if i<j and nums[i]+nums[j]<target:
                    results+=1

        return results
# @lc code=end

