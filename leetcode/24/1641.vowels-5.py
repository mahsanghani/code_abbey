#
# @lc app=leetcode id=1641 lang=python3
#
# [1641] Count Sorted Vowel Strings
#

# @lc code=start
class Solution:
    def countVowelStrings(self, n: int) -> int:
        i,j,k = 1,1,1
        for k in range(5,5+n):
            i = (i*k)//j
            j+=1
        return i
# @lc code=end

