#
# @lc app=leetcode id=1166 lang=python3
#
# [1166] Design File System
#

# @lc code=start
import collections
from collections import defaultdict
class FileSystem:

    def __init__(self):
        self.paths = collections.defaultdict()

    def createPath(self, path: str, value: int) -> bool:
        if path in self.paths or len(path) == 0 or path == "/":
            return False
        
        parent = path[:path.rfind('/')]
        if len(parent)>1 and parent not in self.paths:
            return False

        self.paths[path] = value
        return True

    def get(self, path: str) -> int:
        return self.paths.get(path, -1)


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.createPath(path,value)
# param_2 = obj.get(path)
# @lc code=end

