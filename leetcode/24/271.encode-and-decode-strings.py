#
# @lc app=leetcode id=271 lang=python3
#
# [271] Encode and Decode Strings
#
# @lc code=start
class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        return '!$!$'.join(strs)

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        return s.split('!$!$')

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.encode(strs)
# codec.decode(codec.encode(strs))
# @lc code=end

