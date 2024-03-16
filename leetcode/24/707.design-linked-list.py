#
# @lc app=leetcode id=707 lang=python3
#
# [707] Design Linked List
#
# @lc code=start
class ListNode:
    def __init__(self, value, next = None):
        self.value = value
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = self.tail = None

    def get(self, index: int) -> int:
        cur = self.head
        i = 0
        while (cur != None):
            if i == index:
                return cur.value
            cur = cur.next
            i+=1
        return -1
    
    def insertHead(self, val: int) -> None:
        listNode = ListNode(val) 
        if self.head == None and self.tail == None:
            self.head = self.tail = listNode
        else:
            listNode.next = self.head.next
            self.head.next = listNode        

    def insertTail(self, val: int) -> None:
        listNode = ListNode(val)
        if self.head == None and self.tail == None:
            self.head = self.tail = listNode
        else:
            self.tail.next = listNode
            tail = listNode

    def remove(self, index: int) -> bool:
        cur = self.head
        i = 0
        while (cur != None):
            if i == index:
                if(cur.next):
                    cur.next = cur.next.next
                    return True
                else:

                    return True
            cur = cur.next
            i+=1
        return False

    def getValues(self) -> List[int]:
        cur = self.head
        k = []
        while (cur != None):
            k.append(cur.value)
            cur = cur.next
        return k

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)

