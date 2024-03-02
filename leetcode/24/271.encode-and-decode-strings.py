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
        results = ""
        for s in strs:
            results+=str(len(s))+"#"+s
        return results

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        results = []
        i,j = 0,0
        while i<len(s):
            j=i
            while s[j]!="#":
                j+=1
            length = int(s[i:j])
            results.append(s[j+1:j+1+length])
            i = j+1+length
        return results

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.encode(strs)
# codec.decode(codec.encode(strs))
# @lc code=end

