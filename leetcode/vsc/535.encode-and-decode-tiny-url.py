#
# @lc app=leetcode id=535 lang=python3
#
# [535] Encode and Decode TinyURL
#

# @lc code=start
class Codec:

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        results=""
        for s in longUrl:
            results+=str(len(s))+"#"+s
        return results
        

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        i=0
        results=[]

        while i<len(s):
            j=i
            while s[j]!="#":
                j+=1
            length=int(s[i:j])
            results.append(s[j+1:j+1+length])
            i=j+1+length
        return results
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
# @lc code=end

