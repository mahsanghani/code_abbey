class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s)<len(p):
            return []

        pc = {}
        sc = {}

        for i in range(len(p)):
            pc[p[i]] = 1+pc.get(p[i],0)
            sc[s[i]] = 1+sc.get(s[i],0)
            
        res = [0] if sc == pc else []

        l = 0

        for r in range(len(p),len(s)):
            sc[s[r]] = 1 + sc.get(s[r],0)
            sc[s[l]] -= 1

            if sc[s[l]] == 0:
                sc.pop(s[l])

            l += 1

            if sc == pc:
                res.append(l)

        return res