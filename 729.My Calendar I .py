"""
========================================================================================================================================================================
                                                              BRUTE FORCE APPROACH WITH SIMPLE MAP  O(N)^2 Time_Complexity
========================================================================================================================================================================                                                              
"""

class MyCalendar(object):
    def __init__(self):
        self.calendar = []

    def book(self, start, end):
        for s, e in self.calendar:
            if s < end and start < e:
                return False
        self.calendar.append((start, end))
        return True
      
"""
=========================================================================================================================================================================
                                                         OPTIMIZED APPROACH USING BINARY TREE 
=========================================================================================================================================================================
""""
class Node:
    __times__ = 'start', 'end', 'left' ,'right'
    def __init__(self,start,end):
        self.start = start
        self.end = end
        self.left = self.right = None
    
    def insert(self,node):
        if node.start >= self.end:
            if not self.right:
                self.right = node
                return True
            return self.right.insert(node)
        elif node.end <= self.start:
            if not self.left:
                self.left = node
                return True
            return self.left.insert(node)
        else:
            return False
        






class MyCalendar(object):
    def __init__(self):
        self.root = None

    def book(self, start, end):
        if self.root is None:
            self.root = Node(start,end)
            return True
        return self.root.insert(Node(start,end))
