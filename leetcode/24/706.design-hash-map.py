#
# @lc app=leetcode id=706 lang=python3
#
# [706] Design HashMap
#
# @lc code=start
class ListNode:
    def __init__(self,key,val,next):
        self.key = key
        self.val = val
        self.next = next
class MyHashMap:
    def __init__(self):
        self.map = [ListNode() for i in range(1000)]

    def hash(self, key):
        return key % len(self.map)

    def put(self, key: int, value: int) -> None:
        curr = self.map[self.hash(key)]
        while curr.next:
            if curr.next.key == key:
                curr.next.val = value
                return
            curr = curr.next
        curr.next = ListNode(key, value)

    def get(self, key: int) -> int:
        curr = self.map[self.hash(key)]
        while curr and curr.key != key:
            curr = curr.next
        if curr:
            return curr.val
        return -1

    def remove(self, key: int) -> None:
        curr = self.map[self.hash(key)]
        while curr.next and curr.next.key != key:
            curr = curr.next
        if curr and curr.next:
            curr.next = curr.next.next
        return


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
# @lc code=end

