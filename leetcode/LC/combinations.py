class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        results = []

        def dfs(s, c):
            if len(c) == k:
                results.append(c.copy())
                return

            for i in range(s, n + 1):
                c.append(i)
                dfs(i + 1, c)
                c.pop()

        dfs(1, [])
        return results
