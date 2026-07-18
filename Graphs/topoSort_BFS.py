from collections import defaultdict,deque
class Solution:
    def topoSort(self, V, edges):
        # Code here
        adj = defaultdict(list)
        indeg = [0] * V

        for u, v in edges:
            adj[u].append(v)
            indeg[v] += 1
        topo_order = []
        q = deque(i for i in range(V) if indeg[i] == 0)

        visited = 0

        while q:
            node = q.popleft()
            topo_order.append(node)
            visited += 1

            for nei in adj[node]:
                indeg[nei] -= 1
                if indeg[nei] == 0:
                    q.append(nei)

        return topo_order