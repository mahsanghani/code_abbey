class Logger:

    def __init__(self):
        self.ok = {}

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if timestamp<self.ok.get(message,0):
            return False
        self.ok[message] = timestamp + 10
        return True


# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)