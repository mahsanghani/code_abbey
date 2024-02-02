#
# @lc app=leetcode id=1572 lang=python3
#
# [1572] Matrix Diagonal Sum
#

# @lc code=start
class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        total = 0
        i,j = 0,len(mat)-1
        while i<len(mat):
            total+=mat[i][i]
            if i!=j:
                total+=mat[i][j]
            i+=1
            j-=1
        return total
# @lc code=end

