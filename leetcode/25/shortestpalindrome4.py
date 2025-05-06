class Solution:
    def shortestPalindrome(self, s: str) -> str:
        hash_base = 29
        mod_value = int(1e9 + 7)
        forward_hash = 0
        reverse_hash = 0
        power_value = 1
        palindrome_end_index = -1
        
        for i,j in enumerate(s):
            forward_hash = (
                forward_hash * hash_base + (ord(j) - ord("a") + 1)) % mod_value

            reverse_hash = (
                reverse_hash + (ord(j) - ord("a")+1) * power_value) % mod_value

            power_value = (power_value * hash_base) % mod_value

            if forward_hash == reverse_hash:
                palindrome_end_index = i

        suffix = s[palindrome_end_index+1:]
        reversed_suffix = suffix[::-1]
        return reversed_suffix + s
    