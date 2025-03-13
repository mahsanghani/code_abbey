from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        res=''
        c = list(s)
        counts = Counter(c)
        counts = dict(sorted(counts.items(), key=lambda x: x[1], reverse=True))
        for k,v in counts.items():
            res+=k*v

        return res
