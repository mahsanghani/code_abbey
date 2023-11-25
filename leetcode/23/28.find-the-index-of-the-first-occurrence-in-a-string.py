#
# @lc app=leetcode id=28 lang=python3
#
# [28] Find the Index of the First Occurrence in a String
#

# @lc code=start
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == "":
            return 0
        lps = [0] * len(needle)

        p = 0
        i = 1
        while i < len(needle):
            if needle[i] == needle[p]:
                lps[i] = p + 1
                p += 1
                i += 1
            elif p == 0:
                lps[i] = 0
                i += 1
            else:
                p = lps[p - 1]

        i = 0
        j = 0
        while i < len(haystack):
            if haystack[i] == needle[j]:
                i,j = i+1, j+1
            else:
                if j==0:
                    i += 1
                else:
                    j = lps[j-1]
            if j == len(needle):
                return i-len(needle)
        
        return -1
# @lc code=end

