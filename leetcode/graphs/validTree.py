class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if not n:
            return True

        adj = {i: [] for i in range(n)}

        for j, k in edges:
            adj[j].append(k)
            adj[k].append(j)

        visit = set()

        def dfs(i, j):
            if i in visit:
                return False

            visit.add(i)
            for k in adj[i]:
                if k == j:
                    continue
                if not dfs(k, i):
                    return False

            return True

        return dfs(0, -1) and n == len(visit)