class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        parents = [i for i in range(n)]
        rank = [1] * n

        def find(n1):
            results = n1
            while results != parents[results]:
                parents[results] = parents[parents[results]]
                results = parents[results]
            return results

        def union(n1, n2):
            p1 = find(n1)
            p2 = find(n2)

            if p1 == p2:
                return 0

            if rank[p2] > rank[p1]:
                parents[p1] = p2
                rank[p2] += rank[p1]
            else:
                parents[p2] = p1
                rank[p1] += rank[p2]
            return 1

        results = n
        for n1, n2 in edges:
            results -= union(n1, n2)
        return results