#
# @lc app=leetcode id=2055 lang=python3
#
# [2055] Plates Between Candles
#
# @lc code=start
class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        res = []
        pfx = [0]*(len(s)+1)
        prev = [0]*(len(s)+1)
        next = [float('inf')]*(len(s)+1)

        for i,j in enumerate(s):
            pfx[i+1] = pfx[i] + (j=='|')
            prev[i+1] = i if j=='|' else prev[i]

        for i,j in reversed(list(enumerate(s))):
            next[i] = i if j=='|' else next[i+1]

        for q in queries:
            l,r = next[q[0]], prev[q[1]+1]
            res.append(r-l-(pfx[r]-pfx[l]) if l<r else 0)

        return res

# @lc code=end