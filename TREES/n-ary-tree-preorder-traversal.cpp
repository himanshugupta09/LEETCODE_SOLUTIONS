"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if not root: 
            return None
        preorder = [] 
        stack = [deque([root])]
        while stack:
            level = stack.pop()
            node = level.popleft()
            preorder.append(node.val)
            Q = deque([])
            for child in node.children:
                Q.append(child)
            for remain in level:
                Q.append(remain)
            if Q:
                stack.append(Q)
        return preorder
            
            
                    
                    
        
