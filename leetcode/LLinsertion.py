# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # dummy
        # find node out of order
        # insert to head or
        # insert between nodes

        if (head == None):
            return head

        dummy = ListNode(0, head)
        previous, current = head, head.next

        while current:
            if current.val >= previous.val:
                previous, current = current, current.next
                continue

            temp = dummy
            while current.val > temp.next.val:
                temp = temp.next

            previous.next = current.next
            current.next = temp.next
            temp.next = current
            current = previous.next

        return dummy.next
