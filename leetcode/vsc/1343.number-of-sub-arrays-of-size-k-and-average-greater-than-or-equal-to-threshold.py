#
# @lc app=leetcode id=1343 lang=python3
#
# [1343] Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
#

# @lc code=start
class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        results = 0
        current = sum(arr[:k-1])

        for L in range(len(arr)-k+1):
            current += arr[L+k-1]
            if (current/k)>=threshold:
                results+=1
            current-=arr[L]
        return results
# @lc code=end

