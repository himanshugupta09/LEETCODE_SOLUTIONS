from collections import deque,defaultdict
class Solution:
    def isBipartite(self, V, edges):
        # code here
        color = [-1 for i in range(V)]
        adj = defaultdict(list)
        for node_pair in edges:
            adj[node_pair[0]].append(node_pair[1])
            adj[node_pair[1]].append(node_pair[0])
        queue = deque()
        
        for nodes in edges:
            if color[nodes[0]] == -1:
                color[nodes[0]] = 0
                queue.append(nodes[0])
                while queue:
                    u = queue.popleft()
                    for neigh in adj[u]:
                        if color[neigh] == -1:
                            color[neigh] = 1-color[u]
                            queue.append(neigh)
                        elif color[neigh] == color[u]:
                            return False
        return True
                
                
                