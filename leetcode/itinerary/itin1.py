class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        adj = {s: [] for s, d in tickets}

        tickets.sort()
        for s, d in tickets:
            adj[s].append(d)

        result = ["JFK"]

        def dfs(s):
            if len(result) == len(tickets) + 1:
                return True
            if s not in adj:
                return False

            temp = list(adj[s])
            for k, v in enumerate(temp):
                adj[s].pop(k)
                result.append(v)
                if dfs(v):
                    return True
                adj[s].insert(k, v)
                result.pop()
            return False

        dfs("JFK")
        return result
