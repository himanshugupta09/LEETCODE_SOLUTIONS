"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
from collections import deque
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        hash_map = {}
        q = deque([node])
        hash_map[node] = Node(node.val)

        while q:
            front = q.popleft()
            for neigh in front.neighbors:
                if neigh not in hash_map:
                    hash_map[neigh] = Node(neigh.val)
                    q.append(neigh)
                hash_map[front].neighbors.append(hash_map[neigh])
        return hash_map[node]


        

        