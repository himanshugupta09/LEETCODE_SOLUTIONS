class Solution {
public:
    int ans = 0;
    void dfs(int node,int parent,vector<vector<pair<int,int>>>& adj)
    {
        for(auto& [child,sign]:adj[node])
        {
            if(child != parent)
            {
                ans += sign;
                dfs(child,node,adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<pair<int,int>>>adj(n);

        for(auto& node:connections)
        {
            adj[node[0]].push_back({node[1],1});
            adj[node[1]].push_back({node[0],0});
        }

        vector<bool>vis(n,false);

        dfs(0,-1,adj);

        return ans;

    }
};
