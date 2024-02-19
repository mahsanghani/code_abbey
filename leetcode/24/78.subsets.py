#
# @lc app=leetcode id=78 lang=python3
#
# [78] Subsets
#

# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        results = []
        subsets = []
        
        def dfs(node):
            if node>=len(nums):
                results.append(subsets.copy())
                return None
            subsets.append(nums[node])
            dfs(node+1)
            subsets.pop()
            dfs(node+1)

        dfs(0)
        return results
# @lc code=end

