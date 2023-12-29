#
# @lc app=leetcode id=1329 lang=python3
#
# [1329] Sort the Matrix Diagonally
#

# @lc code=start
from heapq import heapify
from collections import defaultdict
class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        rows = len(mat)
        cols = len(mat[0])
        diag = defaultdict(list)

        for row in range(rows):
            for col in range(cols):
                diag[row-col].append(mat[row][col])

        for each in diag.values():
            heapify(each)

        for row in range(rows):
            for col in range(cols):
                value = heapq.heappop(diag[row-col])
                mat[row][col] = value
        return mat
# @lc code=end

