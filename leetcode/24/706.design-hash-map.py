#
# @lc app=leetcode id=706 lang=python3
#
# [706] Design HashMap
#
# @lc code=start
class ListNode:
    def __init__(self, key):
        self.key = key
        self.next = None

class MyHashMap:
    def __init__(self):
        self.set = [ListNode(0) for i in range(10**4)]

    def put(self, key: int, value: int) -> None:
        cur = self.set[key%len(self.set)]

    def get(self, key: int) -> int:
        cur = self.set[key%len(self.set)]

    def remove(self, key: int) -> None:
        cur = self.set[key%len(self.set)]


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
# @lc code=end

