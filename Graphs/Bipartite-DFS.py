from collections import defaultdict

class Solution:
    def isBipartite(self, V, edges):
        color = [-1] * V
        adj = defaultdict(list)

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        def dfs(u):
            for neigh in adj[u]:
                if color[neigh] == -1:
                    color[neigh] = 1 - color[u]
                    if not dfs(neigh):
                        return False

                elif color[neigh] == color[u]:
                    return False

            return True

        for i in range(V):
            if color[i] == -1:
                color[i] = 0
                if not dfs(i):
                    return False

        return True