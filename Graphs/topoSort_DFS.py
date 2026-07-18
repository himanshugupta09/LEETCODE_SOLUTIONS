from collections import defaultdict
class Solution:
    def topoSort(self, V, edges):
        # Code here
        adj = defaultdict(list)
        indeg = [0] * V

        for u, v in edges:
            adj[u].append(v)
            indeg[v] += 1
        topo_order = []
        stack = []
        for i in range(V):
            if indeg[i] == 0:
                stack.append(i)

        visited = 0

        while stack:
            top = stack[-1]
            stack.pop()
            visited += 1
            topo_order.append(top)
            for neigh in adj[top]:
                indeg[neigh] -= 1
                if indeg[neigh] == 0:
                    stack.append(neigh)
                    

        return topo_order