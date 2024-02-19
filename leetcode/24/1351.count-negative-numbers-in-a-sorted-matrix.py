#
# @lc app=leetcode id=1351 lang=python3
#
# [1351] Count Negative Numbers in a Sorted Matrix
#

# @lc code=start
class Solution:
    def binary_search(self, row: List[int]) -> int:
        left,right = 0,len(row)-1
        while left<=right:
            mid = left + (right-left) // 2
            if row[mid] < 0:
                right = mid - 1
            else:
                left = mid + 1
        return len(row) - left

    def countNegatives(self, grid: List[List[int]]) -> int:
        results = 0
        for row in grid:
            results += self.binary_search(row)
        return results
# @lc code=end

