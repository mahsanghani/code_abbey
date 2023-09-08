#
# @lc app=leetcode id=332 lang=python3
#
# [332] Reconstruct Itinerary
#

# @lc code=start
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        adj = {s:[] for s,d in tickets}

        tickets.sort()
        results = ["JFK"]

        for s,d in tickets:
            adj[s].append(d)

        def dfs(c):
            if len(results)==len(tickets)+1:
                return True
            if c not in adj:
                return False
            
            temp = list(adj[c])

            for k,v in enumerate(temp):
                adj[c].pop(k)
                results.append(v)
                if dfs(v):
                    return True
                adj[c].insert(k,v)
                results.pop()

        dfs("JFK")
        return results

# @lc code=end

