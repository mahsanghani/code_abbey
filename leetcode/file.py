class FileSystem:

    def __init__(self):
        self.d = {"":-1}

    def createPath(self, path: str, value: int) -> bool:
        parent = path[:path.rfind("/")]
        if parent in self.d and path not in self.d:
            self.d[path] = value
            return True
        return False

    def get(self, path: str) -> int:
        return self.d.get(path,-1)


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.createPath(path,value)
# param_2 = obj.get(path)