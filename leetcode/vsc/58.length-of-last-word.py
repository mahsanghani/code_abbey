#
# @lc app=leetcode id=58 lang=python3
#
# [58] Length of Last Word
#

# @lc code=start
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        l=0
        for c in s[::-1]:
            if c==" ":
                if l>0:
                    return l
            else:
                l+=1
        return l
# @lc code=end

