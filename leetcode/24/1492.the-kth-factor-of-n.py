#
# @lc app=leetcode id=1492 lang=python3
#
# [1492] The kth Factor of n
#

# @lc code=start
class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        results = []
        for i in range(1,n+1):
            if n%i==0:
                results.append(i)
        return results[k-1] if len(results)>=k else -1
# @lc code=end

