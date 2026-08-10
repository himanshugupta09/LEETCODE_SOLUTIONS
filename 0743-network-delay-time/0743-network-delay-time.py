import heapq
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj = [[] for _ in range(n)]
        for u,v,w in times:
            adj[u-1].append((w,v))
        min_heap = [(0,k)]
        vis = set()
        min_time = 0
        while min_heap:
            time,node = heapq.heappop(min_heap)
            if node not in vis:
                min_time = max(min_time,time)
                vis.add(node)
                for edge_weight, next_node in adj[node-1]:
                    heapq.heappush(min_heap,(time+edge_weight,next_node))
        return min_time if len(vis) == n else -1