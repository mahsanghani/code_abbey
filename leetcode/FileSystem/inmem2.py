class FileSystem:

    def __init__(self):
        self.trie = {}

    def ls(self, path: str) -> List[str]:
        if len(path) == 1:
            return sorted(self.trie.keys())
        path = path.split('/')
        node = self.trie
        for p in path[1:]:
            node = node.setdefault(p, {})
        if type(node) == str:
            return [path[-1]]
        return sorted(node.keys())

    def mkdir(self, path: str) -> None:
        path = path.split('/')
        node = self.trie
        for p in path[1:]:
            node = node.setdefault(p, {})

    def addContentToFile(self, path: str, content: str) -> None:
        path = path.split('/')
        f = path[-1]
        node = self.trie
        for p in path[1:-1]:
            node = node.setdefault(p, {})
        if f not in node:
            node[f] = content
        else:
            node[f] += content

    def readContentFromFile(self, path: str) -> str:
        path = path.split('/')
        f = path[-1]
        node = self.trie
        for p in path[1:-1]:
            node = node.setdefault(p, {})

        return node[f]

# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)
