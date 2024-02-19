#
# @lc app=leetcode id=78 lang=python3
#
# [78] Subsets
#

# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        subsets = []
        results = []

        def dfs(i):
            if i>=len(nums):
                results.append(subsets.copy())
                return
            subsets.append(nums[i])
            dfs(i+1)
            subsets.pop()
            dfs(i+1)
        
        dfs(0)
        return results

# @lc code=end

