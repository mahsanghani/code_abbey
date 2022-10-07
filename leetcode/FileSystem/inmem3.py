from sortedcontainers import SortedDict


class Node:
    def __init__(self):
        self.content = ''
        self.children = SortedDict()


class FileSystem:
    def __init__(self):
        self.root = Node()

    def ls(self, path: str) -> List[str]:
        path = ['/'] + [p for p in path.split('/') if p]
        node = self.root
        for p in path:
            if p not in node.children:
                node.children[p] = Node()
            node = node.children[p]
        return [path[-1]] if node.content else node.children.keys()

    def mkdir(self, path: str) -> None:
        path = ['/'] + [p for p in path.split('/') if p]
        node = self.root
        for p in path:
            if p not in node.children:
                node.children[p] = Node()
            node = node.children[p]
        return node

    def addContentToFile(self, path: str, content: str) -> None:
        path = ['/'] + [p for p in path.split('/') if p]
        node = self.root
        for p in path:
            if p not in node.children:
                node.children[p] = Node()
            node = node.children[p]
        node.content += content

    def readContentFromFile(self, path: str) -> str:
        path = ['/'] + [p for p in path.split('/') if p]
        node = self.root
        for p in path:
            if p not in node.children:
                return ''
            node = node.children[p]
        return node.content

# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)
