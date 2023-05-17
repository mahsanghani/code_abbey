#
# @lc app=leetcode id=58 lang=python3
#
# [58] Length of Last Word
#

# @lc code=start
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        l=0
        for i in range(len(s)-1,-1,-1):
            if s[i]==" ":
                if l>0:
                    return l
            else:
                l+=1
        return l
# @lc code=end

