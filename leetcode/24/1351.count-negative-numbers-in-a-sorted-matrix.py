#
# @lc app=leetcode id=1351 lang=python3
#
# [1351] Count Negative Numbers in a Sorted Matrix
#

# @lc code=start
class Solution:
    def binary_search(self, row: List[int]) -> int:
        l,r = 0,len(row)-1
        while l<=r:
            m = l+(r-l)//2
            if row[m]<0:
                r=m-1
            else:
                l=m+1
        return len(row)-l

    def countNegatives(self, grid: List[List[int]]) -> int:
        results = 0
        for row in grid:
            results += self.binary_search(row)
        return results
# @lc code=end

