#
# @lc app=leetcode id=78 lang=python3
#
# [78] Subsets
#

# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        subsets,results = [],[]
        def dfs(num):
            if num>=len(nums):
                results.append(subsets.copy())
                return
            subsets.append(nums[num])
            dfs(num+1)
            subsets.pop()
            dfs(num+1)
        dfs(0)
        return results
# @lc code=end

