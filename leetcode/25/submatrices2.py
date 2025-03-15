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
                count = defaultdict(int)
                count[0] = 1
                for col in range(cols):
                    cur_sum = sub_sum[row2][col] - (sub_sum[row1-1][col] if row1>0 else 0)
                    res += count[cur_sum - target]
                    count[cur_sum] += 1

        return res
