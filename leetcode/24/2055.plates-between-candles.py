#
# @lc app=leetcode id=2055 lang=python3
#
# [2055] Plates Between Candles
#
# @lc code=start
class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        results = []
        candles = [i for i,j in enumerate(s) if j=='|']

        def bns(x):
            l,r = 0,len(candles)-1
            
            while l<=r:
                m=(l+r)//2
                if candles[m]<x:
                    l=m+1
                else:
                    r=m-1
            return l


        for x,y in queries:
            l,r = bns(x), bns(y+1)-1
            results.append(candles[r] - candles[l] - (r-l) if l<r else 0)
        return results
    
# @lc code=end