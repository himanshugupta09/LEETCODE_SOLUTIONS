class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>vis(V,0);
        
        unordered_map<int,vector<int>>mpp;
        for(auto node:edges)
        {
            mpp[node[0]].push_back(node[1]);
            mpp[node[1]].push_back(node[0]);
        }
        queue<pair<int,int>>q;
        q.push({0,-1});
        
        for (int i = 0; i < V; i++) {
        if (!vis[i]) {
    
            queue<pair<int,int>> q;
            q.push({i, -1});
            vis[i] = 1;
    
            while (!q.empty()) {
    
                auto [node, parent] = q.front();
                q.pop();
    
                for (auto neigh : mpp[node]) {
    
                    if (!vis[neigh]) {
                        vis[neigh] = 1;
                        q.push({neigh, node});
                    }
                    else if (neigh != parent) {
                        return true;
                    }
                }
            }
        }
    }
    
    return false;
        
    }
};
