#
# @lc app=leetcode id=705 lang=python3
#
# [705] Design HashSet
#
# @lc code=start
class ListNode:
    def __init__(self,key):
        self.key = key
        self.next = None

class MyHashSet:
    def __init__(self):
        self.set = [ListNode(0) for i in range(10**4)]

    def add(self, key: int) -> None:
        curr = self.set[key%len(self.set)]
        while curr.next:
            if curr.next.key == key:
                return
            curr = curr.next
        curr.next = ListNode(key)

    def remove(self, key: int) -> None:
        curr = self.set[key%len(self.set)]

    def contains(self, key: int) -> bool:
        curr = self.set[key%len(self.set)]


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
# @lc code=end

