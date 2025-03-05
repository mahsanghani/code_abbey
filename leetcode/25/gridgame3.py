class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        res = float("inf")
        top = sum(grid[0])
        bot = 0

        for i in range(len(grid[0])):
            top -= grid[0][i]
            res = min(res, max(top,bot))
            bot += grid[1][i]

        return res