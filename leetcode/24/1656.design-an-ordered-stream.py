#
# @lc app=leetcode id=1656 lang=python3
#
# [1656] Design an Ordered Stream
#
# @lc code=start
class OrderedStream:
    def __init__(self, n: int):
        self.map = {}
        for i in range(n):
            self.map[i] = []

    def insert(self, idKey: int, value: str) -> List[str]:
        self.map[idKey].insert(value)
        return self.map

# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)
# @lc code=end

