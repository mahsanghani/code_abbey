#
# @lc app=leetcode id=1656 lang=python3
#
# [1656] Design an Ordered Stream
#
# @lc code=start
class OrderedStream:
    def __init__(self, n: int):
        self.data = [None] * n
        self.ptr = 0

    def insert(self, idKey: int, value: str) -> List[str]:
        self.data[idKey-1] = value
        if idKey-1 > self.ptr:
            return []
        else:
            while self.ptr < len(self.data) and self.data[self.ptr]:
                self.ptr += 1
            return self.data[idKey-1:self.ptr]

# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)
# @lc code=end

