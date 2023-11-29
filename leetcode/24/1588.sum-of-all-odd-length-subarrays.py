#
# @lc app=leetcode id=1588 lang=python3
#
# [1588] Sum of All Odd Length Subarrays
#

# @lc code=start
class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        results = 0
        for i in range(1,len(arr)+1,2):
            if i%2==1:
                for j in range(len(arr)-i+1):
                    temp = arr[j:j+i]
                    print(temp)
                    results+=sum(temp)
        return results
# @lc code=end

