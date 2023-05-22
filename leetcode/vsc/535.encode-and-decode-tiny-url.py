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
        for c in longUrl:
            results+=str(len(c))+"#"+c
        return results

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        i,j=0,0
        results=[]
        while i<len(shortUrl):
            j=i
            while shortUrl[j]!="#":
                j+=1
            length = int(len(shortUrl[i:j]))
            results.append(shortUrl[j+1:j+1+length])
            i=j+1+length
        return "".join(results)
        
# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
# @lc code=end

