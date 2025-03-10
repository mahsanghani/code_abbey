class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        def rec(row, glass):
            if row<0 or glass<0 or glass>row:
                return 0

            if row==0 and glass==0:
                return poured

            left = max(0, rec(row-1,glass-1)-1)
            right = max(0, rec(row-1,glass)-1)

            return (left+right)/2

        return min(1,rec(query_row,query_glass))
    