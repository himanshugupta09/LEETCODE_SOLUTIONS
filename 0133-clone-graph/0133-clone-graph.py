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
        graph = defaultdict()
        def dfs(node):
            if node is  None:
                return None
            if node in graph:
                return graph[node]
            new_node =  Node(node.val)
            graph[node] = new_node
            #nbrs = node.neighbors
            for next in node.neighbors:
                new_node.neighbors.append(dfs(next))
                    #dfs(neigh)
            return new_node
        print(graph)
        return dfs(node)

        