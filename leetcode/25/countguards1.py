class Solution:
    walls = 3
    guards = 2
    guarded = 1
    unguarded = 0

    def markguarded(self, row: int, col: int, grid: List[List[int]]) -> None:
        for r in range(row-1,-1,-1):
            if grid[r][col] == self.walls or grid[r][col] == self.guards:
                break
            grid[r][col] = self.guarded

        for r in range(row+1, len(grid)):
            if grid[r][col] == self.walls or grid[r][col] == self.guards:
                break
            grid[r][col] = self.guarded

        for c in range(col-1,-1,-1):
            if grid[row][c] == self.walls or grid[row][c] == self.guards:
                break
            grid[row][c] = self.guarded

        for c in range(col+1, len(grid[0])):
            if grid[row][c] == self.walls or grid[row][c] == self.guards:
                break
            grid[row][c] = self.guarded

    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        results = 0
        grid = [[self.unguarded] * n for _ in range(m)]

        for guard in guards:
            grid[guard[0]][guard[1]] = self.guards
        
        for wall in walls:
            grid[wall[0]][wall[1]] = self.walls

        for guard in guards:
            self.markguarded(guard[0], guard[1], grid)

        for row in grid:
            for cell in row:
                if cell == self.unguarded:
                    results += 1

        return results
        