#
# @lc app=leetcode id=1472 lang=python3
#
# [1472] Design Browser History
#
# @lc code=start
class BrowserHistory:
    def __init__(self, homepage: str):
        self.history = []
        self.future = []
        self.current = homepage
        
    def visit(self, url: str) -> None:
        self.history.append(self.current)
        self.future = []
        self.current = url

    def back(self, steps: int) -> str:
        while steps > 0 and self.history:
            self.future.append(self.current)
            self.current = self.history.pop()
            steps -= 1
        return self.current
        
    def forward(self, steps: int) -> str:
        while steps > 0 and self.future:
            self.history.append(self.current)
            self.current = self.future.pop()
            steps -= 1
        return self.current

# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
# @lc code=end

