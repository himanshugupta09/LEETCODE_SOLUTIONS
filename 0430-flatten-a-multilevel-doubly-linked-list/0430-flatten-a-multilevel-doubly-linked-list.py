"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        most_recent_next = []
        if not head:
            return head
        curr = head
        while curr:
            if curr.child:
                if curr.next:
                    most_recent_next.append(curr.next)
                curr.next = curr.child
                curr.child.prev = curr
                curr.child = None
            if not curr.next and most_recent_next:
                nxt = most_recent_next.pop()
                curr.next = nxt
                nxt.prev = curr
            curr = curr.next
        return head

           


        