class Solution:
    def shortestPalindrome(self, s: str) -> str:
        length = len(s)
        rvrsd = s[::-1]
        
        for i in range(length):
            if s[:length-i] == rvrsd[i:]:
                return rvrsd[:i]+s

        return ""
    