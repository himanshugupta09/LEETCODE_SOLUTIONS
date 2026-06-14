# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        lst_len = 1
        curr = head
        if not head:
            return head
        while curr.next:
            lst_len += 1
            curr = curr.next
        k = lst_len-(k%lst_len)
        curr.next = head
        while k > 0:
            curr = curr.next
            k -= 1
        head = curr.next
        curr.next = None
        return head





        