#
# @lc app=leetcode id=323 lang=python3
#
# [323] Number of Connected Components in an Undirected Graph
#
# @lc code=start
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adj = {i:[] for i in range(n)}

        res = 0
        visit = set()

        for k,v in edges:
            adj[k].append(v)
            adj[v].append(k)

        def dfs(node):
            for j in adj[node]:
                if j not in visit:
                    visit.add(j)
                    dfs(j)
                    
        for i in range(n):
            if i not in visit:
                dfs(i)
                res+=1
        
        return res

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = defaultdict(list)
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
            
        seen = set()
        ans = 0
        
        def dfs(node):            
            for nei in graph[node]:
                if nei not in seen:
                    seen.add(nei)
                    dfs(nei)
                    
        for i in range(n):
            if i not in seen:
                dfs(i)
                ans += 1
                
        return ans
    
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        parents = [i for i in range(n)]
        rank = [1] * (n)

        def find(n):
            p = parents[n]
            while p!=parents[p]:
                parents[p] = parents[parents[p]]
                p = parents[p]
            return p

        def union(n1,n2):
            p1 = find(n1)
            p2 = find(n2)

            if p1==p2:
                return 0

            if rank[p1]>rank[p2]:
                parents[p2] = p1
                rank[p1]+=rank[p2]
            else:
                parents[p1] = p2
                rank[p2]+=rank[p1]
            return 1
        
        results = n
        for n1,n2 in edges:
            results -= union(n1,n2)
        return results
# @lc code=end

