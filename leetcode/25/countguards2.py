class Solution:
    walls = 3
    guards = 2
    guarded = 1
    unguarded = 0

    def recursive(self, row: int, col: int, grid: List[List[int]], direction: str) -> None:
        if (
            row<0
            or row>=len(grid)
            or col<0
            or col>=len(grid[0])
            or grid[row][col] == self.guards
            or grid[row][col] == self.walls
        ):
            return

        grid[row][col] = self.guarded

        if direction=="U":
            self.recursive(row-1,col,grid,"U")
        if direction=="D":
            self.recursive(row+1,col,grid,"D")
        if direction=="L":
            self.recursive(row,col-1,grid,"L")
        if direction=="R":
            self.recursive(row,col+1,grid,"R")

    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        grid = [[self.unguarded] * n for _ in range(m)]

        for guard in guards:
            grid[guard[0]][guard[1]] = self.guards

        for wall in walls:
            grid[wall[0]][wall[1]] = self.walls

        for guard in guards:
            self.recursive(guard[0]-1,guard[1],grid,"U")
            self.recursive(guard[0]+1,guard[1],grid,"D")
            self.recursive(guard[0],guard[1]-1,grid,"L")
            self.recursive(guard[0],guard[1]+1,grid,"R")

        results = sum(row.count(self.unguarded) for row in grid)

        return results
    