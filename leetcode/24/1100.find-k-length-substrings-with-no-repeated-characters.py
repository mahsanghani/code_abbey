#
# @lc app=leetcode id=1100 lang=python3
#
# [1100] Find K-Length Substrings With No Repeated Characters
#
# @lc code=start
class Solution:
    def numKLenSubstrNoRepeats(self, s: str, k: int) -> int:
        results = []
        if len(s)<k:
            return 0
        for i in range(len(s)-k+1):
            sub = s[i:i+k]
            if len(set(sub))==k:
                results.append(sub)
        return len(results)
# @lc code=end

