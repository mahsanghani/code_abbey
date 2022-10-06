# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0,head)
        previous = dummy
        current = head
        
        while current and current.next:
            nxtpair = current.next.next
            second = current.next
            second.next = current
            current.next = nxtpair
            previous.next = second
            previous = second.next
            current = nxtpair
            
        return dummy.next