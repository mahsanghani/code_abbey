from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        counts = collections.Counter(s)
        max_freq = max(counts.values())

        buckets = [[] for _ in range(max_freq+1)]

        for j,i in counts.items():
            buckets[i].append(j)

        string_builder = []
        
        for i in range(len(buckets)-1,0,-1):
            for c in buckets[i]:
                string_builder.append(c*i)

        return ''.join(string_builder)
