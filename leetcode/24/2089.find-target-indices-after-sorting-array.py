#
# @lc app=leetcode id=2089 lang=python3
#
# [2089] Find Target Indices After Sorting Array
#

# @lc code=start
class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        nums.sort()
        indices = {}

        for i,j in enumerate(nums):
            if j in indices:
                indices[j].append(i)
            else:
                indices[j] = [i]

        if target in indices:
            return indices[target]
        else:
            return []
# @lc code=end

