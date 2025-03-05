class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        res=[]

        if len(s)<len(p):
            return res

        pc = Counter(p)
        wc = Counter(s[:len(p)])

        for i in range(len(s)-len(p)+1):
            if pc==wc:
                res.append(i)

            if i+len(p)<len(s):
                wc[s[i]]-=1
                if wc[s[i]]==0:
                    del wc[s[i]]

                wc[s[i+len(p)]]+=1

        return res