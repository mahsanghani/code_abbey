#
# @lc app=leetcode id=905 lang=python3
#
# [905] Sort Array By Parity
#

# @lc code=start
class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        odd=[]
        even=[]
        for num in nums:
            if num%2==0:
                even.append(num)
            else:
                odd.append(num)
        return even+odd
# @lc code=end

