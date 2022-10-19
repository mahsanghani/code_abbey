class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        length = sum(matchsticks) // 4
        sides = [0]*4
        
        if sum(matchsticks)/4!=length:
            return False
        matchsticks.sort(reverse=True)
        
        def dfs(i):
            if i==len(matchsticks):
                return True
            used = set()
            for j in range(4):
                if sides[j]+matchsticks[i]<=length and sides[j]+matchsticks[i] not in used:
                    sides[j]+=matchsticks[i]
                    if dfs(i+1):
                        return True
                    sides[j] -= matchsticks[i]
                    used.add(sides[j]+matchsticks[i])
            return False
        
        return dfs(0)
