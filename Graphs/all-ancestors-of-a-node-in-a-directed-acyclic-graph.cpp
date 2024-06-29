class Solution {
public:
    void dfs(int cur,vector<vector<int>>&rels,unordered_set<int>&vis)
    {
        vis.insert(cur);
        
        for(int neigh:rels[cur])
        {
            if(vis.find(neigh) == vis.end())
            {
                dfs(neigh,rels,vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>rels(n);
        
        for(int i=0;i<edges.size();i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            rels[b].push_back(a);
        }
        vector<vector<int>>res;
        
        for(int i=0;i<n;i++)
        {
            vector<int>ans;
            unordered_set<int>vis;
            
            dfs(i,rels,vis);
            for(int node=0;node<n;node++)
            {
                if(node == i) continue;
                if(vis.find(node) != vis.end())
                {
                    ans.push_back(node);
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};
