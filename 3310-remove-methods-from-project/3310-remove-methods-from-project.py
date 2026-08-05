from collections import defaultdict
class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        vis = [0]*n
        adj = defaultdict(list)
        for u,v in invocations:
            adj[u].append(v)

        def dfs(i):
            if not vis[i]:
                vis[i] = 1
                for node in adj[i]:
                    dfs(node)
            else:
                return
        
        dfs(k)
        for u,v in invocations:
            if vis[u] == 0 and vis[v] == 1:
                return list(range(n))
        nodes_remove = []
        for i in range(n):
            if not vis[i]:
                nodes_remove.append(i)
        return nodes_remove