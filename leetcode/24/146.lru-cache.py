#
# @lc app=leetcode id=146 lang=python3
#
# [146] LRU Cache
#
# @lc code=start
class ListNode:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}
        self.left = ListNode(0,0)
        self.right= ListNode(0,0)
        self.left.next = self.right
        self.right.prev = self.left

    def add(self, node):
        p = self.right.prev
        n = self.right
        p.next = node
        n.prev = node
        node.next = n
        node.prev = p

    def sub(self, node):
        p = node.prev
        n = node.next
        p.next = n
        n.prev = p

    def get(self, key: int) -> int:
        

    def put(self, key: int, value: int) -> None:
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# @lc code=end

