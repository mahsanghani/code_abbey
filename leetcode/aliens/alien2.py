class Solution:
    def alienOrder(self, words: List[str]) -> str:
        adj = {i: set() for j in words for i in j}

        for i in range(len(words) - 1):
            w1 = words[i]
            w2 = words[i + 1]

            minlen = min(len(w1), len(w2))

            if len(w1) > len(w2) and w1[:minlen] == w2[:minlen]:
                return ""
            for j in range(minlen):
                if w1[j] != w2[j]:
                    adj[w1[j]].add(w2[j])
                    break

        visit = {}
        results = []

        def dfs(c):
            if c in visit:
                return visit[c]

            visit[c] = True
            for n in adj[c]:
                if dfs(n):
                    return True
            visit[c] = False
            results.append(c)

        for c in adj:
            if dfs(c):
                return ""

        return "".join(results[::-1])
