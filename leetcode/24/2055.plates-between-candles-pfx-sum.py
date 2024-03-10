#
# @lc app=leetcode id=2055 lang=python3
#
# [2055] Plates Between Candles
#
# @lc code=start
class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        results = []
        prefix = [0]*(len(s)+1)
        prev = [0]*(len(s)+1)
        next = [float('inf')]*(len(s)+1)

        for i,j in enumerate(s):
            prefix[i+1] = prefix[i] + (j=='|')
            prev[i+1] = i if j=='|' else prev[i]

        for i,j in reversed(list(enumerate(s))):
            next[i] = i if j=='|' else next[i+1]

        for q in queries:
            left = next[q[0]]
            right = prev[q[1]+1]
            results.append(right-left-(prefix[right]-prefix[left]) if left<right else 0)

        return results
# @lc code=end