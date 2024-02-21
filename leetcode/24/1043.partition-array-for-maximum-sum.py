#
# @lc app=leetcode id=1043 lang=python3
#
# [1043] Partition Array for Maximum Sum
#

# @lc code=start
class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        dp = [0]*(n+1)
        for i in range(1,n+1):
            current = 0
            for j in range(1,min(k,i)+1):
                current = max(current,arr[i-j])
                dp[i] = max(dp[i],dp[i-j]+current*j)
        return dp[n]
# @lc code=end

