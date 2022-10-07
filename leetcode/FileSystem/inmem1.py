class FileSystem(defaultdict):

    def __init__(self):
        super(FileSystem, self).__init__(FileSystem)
        self.content = ''

    def ls(self, path: str) -> List[str]:
        fs = self.mkdir(path)
        return path.rsplit('/', 1)[-1:] if fs.content else sorted(fs.keys())

    def mkdir(self, path: str) -> 'FileSystem':
        f = filter(None, path.split('/'))
        return reduce(dict.__getitem__, f, self)

    def addContentToFile(self, path: str, content: str) -> None:
        self.mkdir(path).content += content

    def readContentFromFile(self, path: str) -> str:
        return self.mkdir(path).content

# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)
