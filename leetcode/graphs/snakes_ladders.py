class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        length = len(board)
        board.reverse()

        def bfs(s):
            r = (s - 1) // length
            c = (s - 1) % length
            if r % 2:
                c = length - 1 - c
            return [r, c]

        q = deque()
        q.append([1, 0])
        visit = set()
        while q:
            s, m = q.popleft()
            for i in range(1, 7):
                ns = s + i
                r, c = bfs(ns)
                if board[r][c] != -1:
                    ns = board[r][c]
                if ns == length * length:
                    return m + 1
                if ns not in visit:
                    visit.add(ns)
                    q.append([ns, m + 1])
        return -1