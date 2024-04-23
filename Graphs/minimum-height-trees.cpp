class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int,set<int>>adj;
        if(n == 1)
        {
            return {0};
        }
        for(auto node:edges)
        {
            adj[node[0]].insert(node[1]);
            adj[node[1]].insert(node[0]);
        }
        queue<int>q;
        
        for(auto node:adj)
        {
            if(adj[node.first].size() == 1){ 
                q.push(node.first); 
            }
        }
        while(n > 2)
        {
            int c = q.size();
            n -= c;
            
            for(int i=0;i<c;i++)
            {
                int cur = q.front();
                q.pop();
                for(auto neigh:adj[cur])
                {
                    if(adj[neigh].find(cur) != adj[neigh].end())
                    {
                        adj[neigh].erase(cur); 
                    }
                    if(adj[neigh].size() == 1)
                    {
                        q.push(neigh);
                    }
                }
                
            }
        }
        vector<int>res;
        while(!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
