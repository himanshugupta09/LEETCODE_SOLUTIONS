from collections import defaultdict
class Solution:
    def dfs1(self,u,adj,vis,stk):
        vis[u] = 1
        for neigh in adj[u]:
            if not vis[neigh]:
                self.dfs1(neigh,adj,vis,stk)
        stk.push(u)
        
         
    def dfs2(self,u,rev_adj,vis,ssc):
        vis[u] = 1
        ssc.append(u)
        for neigh in rev_adj[u]:
            if not vis[neigh]:
                self.dfs2(neigh,rev_adj,vis)
            
            
        
        
    def kosaraju(self, V, edges):
        # code here
        adj = defaultdict(list)
        rev_adj = defaultdict(list)
        
        for v1,v2 in edges:
            adj[v1].append(v2)
            rev_adj[v2].append(v1)
        vis = [0]*V
        stk = []
        for i in range(V):
            if not vis[i]:
                self.dfs1(i,adj,vis,stk)
        vis = [0]*V
        SSC = []
        while stk:
            u = stk.pop()
            if not vis[u]:
                ssc = []
                self.dfs2(u,rev_adj,vis,ssc)
                SSC.append(ssc)
        return len(SSC)
                
        