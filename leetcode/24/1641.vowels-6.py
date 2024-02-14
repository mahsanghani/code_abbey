#
# @lc app=leetcode id=1641 lang=python3
#
# [1641] Count Sorted Vowel Strings
#

# @lc code=start
class Solution:
    def countVowelStrings(self, n: int) -> int:
        a,e,i,o,u = 1,1,1,1,1

        while n>1:
            o+=u
            i+=o
            e+=i
            a+=e
            n-=1

        return a+e+i+o+u
# @lc code=end

