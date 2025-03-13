class Solution:
    def frequencySort(self, s: str) -> str:
        res = []
        count = Counter(s)
        buckets = defaultdict(list)
        
        for char, freq in count.items():
            buckets[freq].append(char)

        for i in range(len(s), 0, -1):
            if i in buckets:
                for c in buckets[i]:
                    res.append(c*i)

        return ''.join(res)
