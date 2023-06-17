#
# @lc app=leetcode id=1768 lang=python3
#
# [1768] Merge Strings Alternately
#

# @lc code=start
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        i,j,k = 0,0,0
        word3 = []

        while i<len(word1) and j<len(word2):
            word3.append(word1[i])
            word3.append(word2[j])
            i+=1
            j+=1
        word3.append(word1[i:])
        word3.append(word2[j:])

        return "".join(word3)

# @lc code=end

