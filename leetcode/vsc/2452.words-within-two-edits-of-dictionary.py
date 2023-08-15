#
# @lc app=leetcode id=2452 lang=python3
#
# [2452] Words Within Two Edits of Dictionary
#

# @lc code=start
class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        def check(word, query):
            corr=0
            for j in range(len(word)):
                if word[j] != query[j]:
                    corr+=1

            return corr
        
        res = []
        for query in queries:
            if query in dictionary:
                res.append(query)

            else:
                for j in range(len(dictionary)):
                    c = check(dictionary[j], query)
                    if c <= 2:
                        res.append(query)
                        break
                    else:
                        continue
            
        return res
# @lc code=end

