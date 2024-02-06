#
# @lc app=leetcode id=2315 lang=python3
#
# [2315] Count Asterisks
#

# @lc code=start
class Solution:
    def countAsterisks(self, s: str) -> int:
        count, results = 0, 0

        for i in range(len(s)):
            if s[i]=='|':
                count+=1
            if count%2==0 and s[i]=='*':
                results+=1
            i+=1

        return results
# @lc code=end

