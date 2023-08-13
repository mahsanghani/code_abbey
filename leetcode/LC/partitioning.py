class Solution:
    def partition(self, s: str) -> List[List[str]]:
        results = []
        partitions = []

        def dfs(i):
            if i >= len(s):
                results.append(partitions.copy())
                return
            for j in range(i, len(s)):
                if self.pali(s, i, j):
                    partitions.append(s[i:j + 1])
                    dfs(j + 1)
                    partitions.pop()

        dfs(0)
        return results

    def pali(self, s, l, r):
        while l < r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True
