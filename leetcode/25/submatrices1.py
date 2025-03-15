class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        res = 0
        rows = len(matrix)
        cols = len(matrix[0])
        sub_sum = [[0]*cols for _ in range(rows)]

        for row in range(rows):
            for col in range(cols):
                top = sub_sum[row-1][col] if row>0 else 0
                left = sub_sum[row][col-1] if col>0 else 0
                top_left = sub_sum[row-1][col-1] if min(row,col)>0 else 0
                sub_sum[row][col] = matrix[row][col] + top + left - top_left

        for row1 in range(rows):
            for row2 in range(row1,rows):
                for col1 in range(cols):
                    for col2 in range(col1,cols):
                        top = sub_sum[row1-1][col2] if row1>0 else 0
                        left = sub_sum[row2][col1-1] if col1>0 else 0
                        top_left = sub_sum[row1-1][col1-1] if min(row1,col1)>0 else 0
                        cur_sum = sub_sum[row2][col2] - top - left + top_left
                        if cur_sum == target:
                            res += 1

        return res
