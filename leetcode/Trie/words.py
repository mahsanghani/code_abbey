class Node:
    def __init__(self):
        self.children = {}
        self.word = False


class WordDictionary:
    def __init__(self):
        self.root = Node()
        self.max_word_length = 0

    def addWord(self, word: str) -> None:
        current = self.root
        self.max_word_length = max(self.max_word_length, len(word))
        for c in word:
            if c not in current.children:
                current.children[c] = Node()
            current = current.children[c]
        current.word = True

    def search(self, word: str) -> bool:
        if len(word) > self.max_word_length:
            return False

        def dfs(j, root):
            current = root
            for i in range(j, len(word)):
                c = word[i]
                if c == '.':
                    for child in current.children.values():
                        if dfs(i + 1, child):
                            return True
                    return False
                else:
                    if c not in current.children:
                        return False
                current = current.children[c]
            return current.word

        return dfs(0, self.root)

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
