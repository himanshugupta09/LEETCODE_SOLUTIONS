# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self,head:Optional[ListNode])->ListNode:
        prev=  None
        curr = head
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        return prev
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow = head
        fast = head
        if not fast.next.next:
            return head.val+head.next.val
        while fast and fast.next:
            slow = slow.next
            if fast.next.next:
                fast = fast.next.next
            if  not fast.next or not fast.next.next:
                break
        reverse_list = self.reverseList(slow.next)
        slow = head
        max_sum = 0
        while slow and reverse_list:
            sm = slow.val+reverse_list.val
            max_sum = max(max_sum,sm)
            slow = slow.next
            reverse_list = reverse_list.next
        return max_sum
        