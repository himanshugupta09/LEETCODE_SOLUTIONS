"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return node
        q,clones = deque([node]),{node.val:Node(node.val,[])}
        while q:
            now = q.popleft()
            now_clone = clones[now.val]
            
            for neigh in now.neighbors:
                if neigh.val not in clones:
                    clones[neigh.val] = Node(neigh.val,[])
                    q.append(neigh)
                now_clone.neighbors.append(clones[neigh.val])
        
        return clones[node.val]            ;
