import heapq
from collections import defaultdict
class Solution:
    def spanningTree(self, V, edges):
        # code here
        pq = []
        heapq.heappush(pq,(0,0))
        vis = [0]*V
        mst_weight = 0
        adj = defaultdict(list)
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))  
        while pq:
            weight,node = heapq.heappop(pq)
            if vis[node]:
                continue
            vis[node] = 1
            mst_weight += weight
            for adjNode,edwe in adj[node]:
                if not vis[adjNode]:
                    heapq.heappush(pq,(edwe,adjNode))
        return mst_weight
                
                
            