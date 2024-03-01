#
# @lc app=leetcode id=208 lang=python3
#
# [208] Implement Trie (Prefix Tree)
#
# @lc code=start
class Node:
    def __init__(self):
        self.children = {}
        self.endofword = False
class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        current = self.root
        for char in word:
            if char not in current.children:
                current.children[c] = Node()
            current = current.children[c]
        current.endofword = True

    def search(self, word: str) -> bool:
        current = self.root
        for char in word:
            if char not in current.children:
                return False
            current = current.children[c]
        return current.endofword

    def startsWith(self, word: str) -> bool:
        current = self.root
        for char in word:
            if char not in current.children:


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
# @lc code=end

