#
# @lc app=leetcode id=167 lang=python3
#
# [167] Two Sum II - Input Array Is Sorted
#

# @lc code=start
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        d={}
        for i,j in enumerate(numbers):
            if j in d:
                return [d[j]+1,i+1]
            else:
                d[target-j]=i
            
# @lc code=end

