class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        left = 0
        res = 0
        count = defaultdict(int)

        for right in range(len(s)):
            count[s[right]] += 1

            while len(count) == 3:
                res += (len(s) - right)
                count[s[left]] -= 1
                if count[s[left]] == 0:
                    count.pop(s[left])
                left += 1
        
        return res