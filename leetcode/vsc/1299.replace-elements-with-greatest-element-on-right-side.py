#
# @lc app=leetcode id=1299 lang=python3
#
# [1299] Replace Elements with Greatest Element on Right Side
#

# @lc code=start
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        right = -1
        for i in range(len(arr)-1,-1,-1):
            new = max(arr[i],right)
            arr[i] = right
            right = new
        return arr
# @lc code=end

