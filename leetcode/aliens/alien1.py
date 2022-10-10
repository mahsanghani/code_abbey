class Solution:
    def alienOrder(self, words):
        adj = {c: set() for w in words for c in w}  # adjacency list
        # invalid dictionary
        for i in range(len(words) - 1):
            w1, w2 = words[i], words[i + 1]
            minLen = min(len(w1), len(w2))
            if len(w1) > len(w2) and w1[:minLen] == w2[:minLen]:
                return ""
            # traverse each character and find the first different one
            for j in range(minLen):
                if w1[j] != w2[j]:
                    adj[w1[j]].add(w2[j])
                    break

        status = {}  # 0: unvisited; 1: visiting; -1: visited
        ans = []

        def dfs(c):
            if status.get(c, 0) == 1: return False
            if status.get(c, 0) == -1: return True
            status[c] = 1
            for nextChar in adj[c]:
                if not dfs(nextChar): return False
            ans.append(c)
            status[c] = -1
            return True

        for c in adj:
            if not dfs(c): return ""
        return ''.join(ans[::-1])
