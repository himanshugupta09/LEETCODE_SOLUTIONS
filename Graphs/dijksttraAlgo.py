import heapq
from collections import defaultdict
class Solution:
    # Returns shortest distances from src to all other vertices
    def dijkstra(self, V, edges, src):
        dist = [float('inf')] * V
        dist[src] = 0
        
        adj = defaultdict(list)
        
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        
        pq = [(0, src)]
        
        while pq:
            d, u = heapq.heappop(pq)
        
            if d > dist[u]:
                continue
        
            for v, w in adj[u]:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    heapq.heappush(pq, (dist[v], v))
        
        return dist
        