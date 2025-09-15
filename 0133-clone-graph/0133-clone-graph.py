"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        hashmap = defaultdict()
        def dfs(node):
            if node is None:
                return None
            if node in hashmap:
                return hashmap[node]
            cloned = Node(node.val)
            hashmap[node] = cloned
            for next in node.neighbors:
                cloned.neighbors.append(dfs(next))
            return cloned
        return dfs(node)
        