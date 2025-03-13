from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        count = [0]*123

        for c in s:
            count[ord(c)] += 1

        freq = [(chr(i), count[i]) for i in range(123) if count[i]>0]
        freq.sort(key=lambda x: (-x[1],x[0]))

        return ''.join(char*freq for char,freq in freq)
