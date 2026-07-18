class Solution {
  public:
    bool dfs(unordered_map<int,vector<int>>&mpp,int node, set<int>&path,vector<int>&vis)
    {
        if(path.find(node) != path.end())
        {
            return true;
        }
        if(vis[node])
        {
            return false;
        }
        vis[node] = 1;
        path.insert(node);
        for(auto neigh:mpp[node])
        {
            if(dfs(mpp,neigh,path,vis))
            {
                return true;
            }
        }
        path.erase(node);
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,vector<int>>mpp;
        vector<int>vis(V,0);
        
        for(auto node:edges)
        {
            mpp[node[0]].push_back(node[1]);
        }
        set<int>path;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(mpp,i,path,vis)){
                    return true;
                }
            }
        }
        return false;
        
    }
};