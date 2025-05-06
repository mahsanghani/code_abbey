class Solution:
    def shortestPalindrome(self, s: str) -> str:
        if not s:
            return s

        modified = self.preprocess(s)
        n = len(modified)
        palindrome_radius_array = [0]*n
        center = 0
        right_boundary = 0
        max_palindrome_length = 0

        for i in range(1,n-1):
            mirror_index = 2*center-i
            if right_boundary>i:
                palindrome_radius_array[i] = min(
                    right_boundary-i, palindrome_radius_array[mirror_index]
                )

            while (
                modified[i+1+palindrome_radius_array[i]] == modified[i-1-palindrome_radius_array[i]]):
                palindrome_radius_array[i] += 1

            if i+palindrome_radius_array[i] > right_boundary:
                center = i
                right_boundary = i+palindrome_radius_array[i]

            if i-palindrome_radius_array[i]==1:
                max_palindrome_length = max(
                    max_palindrome_length,palindrome_radius_array[i])

        suffix = s[max_palindrome_length:][::-1]
        return suffix+s
        
    def preprocess(self, s: str) -> str:
        return "^" + "#" + "#".join(s) + "#$"
