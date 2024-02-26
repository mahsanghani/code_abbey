#
# @lc app=leetcode id=535 lang=python3
#
# [535] Encode and Decode TinyURL
#
# @lc code=start
class Codec:
    def __init__(self):
        self.prefix = "https://tinyurl.com/"
        self.map = dict()

    def _hash(self, s):
        base = 13331
        mod = 1e9+7
        res = 0
        for c in s:
            res = (res*base + ord(c))%mod
        return res

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL."""
        key = str(self._hash(longUrl))
        self.map[key] = longUrl
        return self.prefix + key

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL."""
        return self.map[shortUrl.split("/")[-1]]
        
# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
# @lc code=end

