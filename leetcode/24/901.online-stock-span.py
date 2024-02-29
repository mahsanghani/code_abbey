#
# @lc app=leetcode id=901 lang=python3
#
# [901] Online Stock Span
#
# @lc code=start
class StockSpanner:
    def __init__(self):
        self.stack = []
        self.count = 0       

    def next(self, price: int) -> int:
        if not self.stack or self.stack[-1][0]>price:
            self.stack.append((price,1))
            return 1
        temp=1
        while self.stack and self.stack[-1][0]<=price:
            # self.stack.pop()[1]
            temp+=self.stack.pop()[1]
        self.stack.append((price,temp))
        return temp


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
# @lc code=end

