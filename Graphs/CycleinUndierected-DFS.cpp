class Solution {
  public:
    bool dfs(vector<int>&vis,int node,int par,unordered_map<int,vector<int>>mpp)
    {
        vis[node] = 1;
        for(auto neigh:mpp[node])
        {
            if(!vis[neigh]){
                if(dfs(vis,neigh,node,mpp))
                    return true;
            }
            else if(neigh != par)
            {
                return true;
            }
            
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>vis(V,0);
        unordered_map<int,vector<int>>mpp;
        for(auto node:edges)
        {
            mpp[node[0]].push_back(node[1]);
            mpp[node[1]].push_back(node[0]);
        }
        for(int i=0;i<V;i++)
        {
            if(!vis[i]){
                if(dfs(vis,i,-1,mpp)){
                    return true;
                }
            }
        }
        return false;
        
    }
};