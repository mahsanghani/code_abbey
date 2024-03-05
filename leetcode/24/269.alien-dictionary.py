#
# @lc app=leetcode id=269 lang=python3
#
# [269] Alien Dictionary
#
# @lc code=start
class Solution:
    def alienOrder(self, words: List[str]) -> str:
        visit = {}
        results = []
        adj = {w:set() for word in words for w in word}

        for i in range(len(words)-1):
            w1,w2 = words[i],words[i+1]
            minlen = min(len(w1),len(w2))

            if len(w1)>len(w2) and w1[:minlen]==w2[:minlen]:
                return ""

            for j in range(minlen):
                if w1[j]!=w2[j]:
                    adj[w1[j]].add(w2[j])
                    break

        def dfs(c):
            if c in visit:
                return visit[c]
            if c not in adj:
                return False
            
            visit[c] = True

            for j in adj[c]:
                if dfs(j):
                    return True
                
            visit[c] = False
            results.append(c)

        for c in adj:
            if dfs(c):
                return ""
            
        return "".join(results[::-1])
# @lc code=end

