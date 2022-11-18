class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid)
        visit = set()
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]

        def invalid(r, c):
            return r < 0 or c < 0 or r == rows or c == cols

        def dfs(r, c):
            if (invalid(r, c) or not grid[r][c] or (r, c) in visit):
                return
            visit.add((r, c))
            for dr, dc in directions:
                dfs(r + dr, c + dc)

        def bfs():
            results = 0
            q = deque(visit)
            while q:
                for i in range(len(q)):
                    r, c = q.popleft()
                    for dr, dc in directions:
                        curr, curc = r + dr, c + dc
                        if invalid(curr, curc) or (curr, curc) in visit:
                            continue
                        if grid[curr][curc]:
                            return results
                        q.append([curr, curc])
                        visit.add((curr, curc))
                results += 1

        for r in range(rows):
            for c in range(cols):
                if grid[r][c]:
                    dfs(r, c)
                    return bfs()