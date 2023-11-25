#
# @lc app=leetcode id=604 lang=python3
#
# [604] Design Compressed String Iterator
#

# @lc code=start
class StringIterator:

    def __init__(self, compressedString: str):
        self.i = 0
        self.n = 0
        self.char = None
        self.data = compressedString

    def next(self) -> str:
        if not self.hasNext():
            return " "
        if not self.n:
            self.char = self.data[self.i]
            self.i = ii = self.i+1
            while self.i < len(self.data) and self.data[self.i].isdigit():
                self.i += 1
            self.n = int(self.data[ii:self.i])
        self.n -= 1
        return self.char

    def hasNext(self) -> bool:
        return self.i < len(self.data) or self.n

# Your StringIterator object will be instantiated and called as such:
# obj = StringIterator(compressedString)
# param_1 = obj.next()
# param_2 = obj.hasNext()
# @lc code=end

