#
# @lc app=leetcode id=23 lang=python3
#
# [23] Merge k Sorted Lists
#
# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists or len(lists)==0:
            return None

        while len(lists)>1:
            merged = []
            
            for i in range(0,len(lists),2):
                list1 = lists[i]
                list2 = lists[i+1] if (i+1)<len(lists) else None
                merged.append(self.merge2lists(list1,list2))
            lists = merged
        return lists[0]

    def merge2lists(self,list1,list2):
        dummy = ListNode()
        temp = dummy

        while list1 and list2:
            if list1.val < list2.val:
                temp.next = list1
                list1 = list1.next
            else:
                temp.next = list2
                list2 = list2.next
            temp = temp.next

        if list1:
            temp.next = list1
        if list2:
            temp.next = list2

        return dummy.next

# @lc code=end

