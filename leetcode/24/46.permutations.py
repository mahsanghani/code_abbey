#
# @lc app=leetcode id=46 lang=python3
#
# [46] Permutations
#

# @lc code=start
class Solution:
    def backtrack(self, nums, path, results):
        if not nums:
            results.append(path)
            return
        for i in range(len(nums)):
            self.backtrack(nums[:i]+nums[i+1:], path + [nums[i]], results)

    def permute(self, nums: List[int]) -> List[List[int]]:
        results = []
        self.backtrack(nums, [], results)
        return results
# @lc code=end

