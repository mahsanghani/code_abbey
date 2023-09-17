#
# @lc app=leetcode id=146 lang=python3
#
# [146] LRU Cache
#

# @lc code=start
import collections
from collections import OrderedDict
class Node:
    def __init__(self, key=None, value=None, prev=None, next=None):
        self.key = key
        self.value = value
        self.prev = prev
        self.next = next

class LRUCache:
    def __init__(self, capacity: int):
        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head
        self.capacity = capacity
        self.dictionary = {}
        
    def push(self, key, value):
        newNode = Node(key=key, value=value, next=self.tail, prev=self.tail.prev)
        newNode.prev.next = newNode
        self.tail.prev = newNode
        self.dictionary[key] = newNode

        if len(self.dictionary) > self.capacity:
            self.pop(self.head.next)

    def pop(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
        del self.dictionary[node.key]

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# @lc code=end

