from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        if not s:
            return s

        s = list(s)

        s.sort()

        all_strings = []
        curr_sb = [s[0]]

        for c in s[1:]:
            if curr_sb[-1]!=c:
                all_strings.append(''.join(curr_sb))
                curr_sb = []
            curr_sb.append(c)
        all_strings.append(''.join(curr_sb))

        all_strings.sort(key=lambda string : len(string), reverse=True)

        return ''.join(all_strings)
