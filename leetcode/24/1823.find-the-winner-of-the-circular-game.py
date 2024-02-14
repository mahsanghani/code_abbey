#
# @lc app=leetcode id=1823 lang=python3
#
# [1823] Find the Winner of the Circular Game
#

# @lc code=start
class ListNode:
    def __init__(self,val=0,next=None):
        self.val = val
        self.next = next
class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        # circular linked list
        head = curr = ListNode()
        for i in range(n):
            curr.next = ListNode(i+1)
            curr = curr.next
        curr.next = head.next
        # eliminate each k person
        while(curr.next!=curr):
            for j in range(k-1):
                curr = curr.next
            curr.next = curr.next.next
        return curr.val
# @lc code=end

