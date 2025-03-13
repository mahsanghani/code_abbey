from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        count = Counter(s)
        sorted_chars = sorted(s, key=lambda x: (-count[x], x))
        return ''.join(sorted_chars)
