#
# @lc app=leetcode id=1472 lang=python3
#
# [1472] Design Browser History
#

# @lc code=start
import heapq
class BrowserHistory:

    def __init__(self, homepage: str):
        self.stack = [homepage]
        self.current = 0
        self.last = self.next = ""
        # self.results.append(None)
        heapq.heapify(self.stack)

    def visit(self, url: str) -> None:
        self.current += 1
        self.stack.append(url)
        # self.results.append(None)

    def back(self, steps: int) -> str:
        # if self.current>=len(self.stack)-steps:
        try:
            for i in range(steps):
                self.current -= 1
                self.last = self.stack[-i]
            return self.last
        except:
            return ""

    def forward(self, steps: int) -> str:
        if self.current<=len(self.stack)+steps:
            for i in range(steps):
                self.current += 1
                self.next = self.stack[i]
        return self.next


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
# @lc code=end

