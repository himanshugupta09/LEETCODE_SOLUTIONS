from typing import List

class Solution:
    
    def find(self, x, par):
        if par[x] != x:
            par[x] = self.find(par[x], par)
        return par[x]
    
    def union(self, u, v, par, size):
        pu = self.find(u, par)
        pv = self.find(v, par)
        
        if pu == pv:
            return
        
        if size[pu] < size[pv]:
            pu, pv = pv, pu
        
        par[pv] = pu
        size[pu] += size[pv]
    
    def kruskalsMST(self, V: int, edges: List[List[int]]) -> int:
        
        edges.sort(key=lambda x: x[2])
        
        size = [1] * V
        par = [i for i in range(V)]
        
        mst = 0
        count = 0
        
        for u, v, w in edges:
            if self.find(u, par) != self.find(v, par):
                self.union(u, v, par, size)
                mst += w
                count += 1
                
                # optional optimization
                if count == V - 1:
                    break
        
        return mst