class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        memo = {(0,0) : poured}

        def rec(row, glass):
            if row<0 or glass<0 or glass>row:
                return 0

            if (row, glass) in memo:
                return memo[(row,glass)]

            left = max(0, rec(row-1,glass-1)-1)
            right = max(0, rec(row-1,glass)-1)

            memo[(row,glass)] = (left + right) / 2
            return memo[(row, glass)]

        return min(1,rec(query_row,query_glass))
