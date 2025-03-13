from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        counts = collections.Counter(s)

        string_builder = []

        for i,j in counts.most_common():
            string_builder.append(j*i)
        
        return ''.join(string_builder)
