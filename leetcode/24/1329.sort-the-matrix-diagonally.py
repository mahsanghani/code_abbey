#
# @lc app=leetcode id=1329 lang=python3
#
# [1329] Sort the Matrix Diagonally
#

# @lc code=start
from heapq import heapify, heappop
from collections import defaultdict
class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        rows = len(mat)
        cols = len(mat[0])
        
        def sortdiag(row,col):
            diag = []
            length = min(rows-row,cols-col)

            for i in range(length):
                diag.append(mat[row+i][col+i])

            heapify(diag)

            for i in range(length):
                mat[row+i][col+i] = heappop(diag)

        for row in range(rows):
            sortdiag(row,0)

        for col in range(cols):
            sortdiag(0,col)

        return mat
# @lc code=end

