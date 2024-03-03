#
# @lc app=leetcode id=953 lang=python3
#
# [953] Verifying an Alien Dictionary
#
# @lc code=start
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        d = {c:i for i,c in enumerate(order)}

        for i in range(len(words)-1):
            w1,w2 = words[i],words[i+1]

            for j in range(len(w1)):
                if j==len(w2):
                    return False

                if w1[j]!=w2[j]:
                    if d[w2[j]]<d[w1[j]]:
                        return False
                    break

        return True
# @lc code=end

