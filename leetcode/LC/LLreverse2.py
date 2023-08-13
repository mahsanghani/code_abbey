# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        # left
        # reverse
        # update

        dummy = ListNode(0, head)
        lp = dummy
        current = head

        for i in range(left - 1):
            lp, current = current, current.next

        previous = None
        for i in range(right - left + 1):
            temp = current.next
            current.next = previous
            previous, current = current, temp

        lp.next.next = current
        lp.next = previous
        return dummy.next
