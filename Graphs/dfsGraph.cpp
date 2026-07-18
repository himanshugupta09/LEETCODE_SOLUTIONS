class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int>dfs(vector<int> &res,vector<int> adj[],int node,vector<bool> &vis)
    {
        vis[node] = 1;
        res.push_back(node);
        
        for(auto i:adj[node])
        {
            if(!vis[i])
            {
                dfs(res,adj,i,vis);
            }
        }
        
        return res;
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V,0);
        vector<int>res;
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                res = dfs(res,adj,i,vis);
            }
        }
        return res;
    }
};
