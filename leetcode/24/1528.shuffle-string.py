#
# @lc app=leetcode id=1528 lang=python3
#
# [1528] Shuffle String
#

# @lc code=start
class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        results = list(s)

        for i in range(len(indices)):
            results[indices[i]]=s[i]

        return ''.join(results)
# @lc code=end

