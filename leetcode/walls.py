class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        rows = len(rooms)
        cols = len(rooms[0])
        q = deque()
        visit = set()

        def dfs(r, c):
            if r < 0 or c < 0 or r == rows or c == cols or (r, c) in visit or rooms[r][c] == -1:
                return
            visit.add((r, c))
            q.append((r, c))

        for r in range(rows):
            for c in range(cols):
                if rooms[r][c] == 0:
                    q.append([r, c])
                    visit.add((r, c))

        distance = 0
        while q:
            for i in range(len(q)):
                r, c = q.popleft()
                rooms[r][c] = distance
                dfs(r + 1, c)
                dfs(r, c + 1)
                dfs(r - 1, c)
                dfs(r, c - 1)
            distance += 1
