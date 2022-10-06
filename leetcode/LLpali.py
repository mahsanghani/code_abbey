# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        # slow
        # fast
        # half
        # flip
        # compare
        
        slow = head
        fast = head
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
        # slow.next half
        # reverse 2nd half 
        
        second = slow
        previous = None
        
        while second:
            temp = second.next
            second.next = previous
            previous = second
            second = temp
            
        left = head
        right = previous
        while right:
            if left.val!=right.val:
                return False
            left = left.next
            right = right.next
        return True