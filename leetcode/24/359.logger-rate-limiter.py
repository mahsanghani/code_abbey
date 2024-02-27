#
# @lc app=leetcode id=359 lang=python3
#
# [359] Logger Rate Limiter
#
# @lc code=start
class Logger:
    def __init__(self):
        self.map = {}

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if message not in self.map:
            self.map[message] = timestamp
            return True
        
        if timestamp>=self.map[message]+10:
            self.map[message] = timestamp
            return True
        return False

# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)
# @lc code=end

