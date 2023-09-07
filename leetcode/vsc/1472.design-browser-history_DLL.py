#
# @lc app=leetcode id=1472 lang=python3
#
# [1472] Design Browser History
#

# @lc code=start
class DLLNode:
    def __init__(self, url: str):
        self.prev = None
        self.next = None
        self.data = url
class BrowserHistory:
    def __init__(self, homepage: str):
        self.head = DLLNode(homepage)
        self.current = self.head
        
    def visit(self, url: str) -> None:
        new_node = DLLNode(url)
        self.current.next = new_node
        new_node.prev = self.current
        self.current = new_node

    def back(self, steps: int) -> str:

    def forward(self, steps: int) -> str:


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
# @lc code=end

