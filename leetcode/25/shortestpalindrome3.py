class Solution:
    def shortestPalindrome(self, s: str) -> str:
        rvrsd = s[::-1]
        comb = s+"#"+rvrsd
        prefix = self.build_prefix_table(comb)
        palindrome_length = prefix[-1]
        suffix = rvrsd[:len(s)-palindrome_length]
        return suffix + s

    def build_prefix_table(self, s: str) -> list:
        prefix = [0]*len(s)
        length = 0

        for i in range(1,len(s)):
            while length > 0 and s[i]!=s[length]:
                length = prefix[length-1]
            if s[i]==s[length]:
                length+=1
            prefix[i] = length
        return prefix
