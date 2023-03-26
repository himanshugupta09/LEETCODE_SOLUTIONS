class Solution {
public:
    int res = -1;
    void dfs(int node,vector<int>& edges,unordered_map<int,int>& mp,vector<bool>& vis)
    {
        vis[node] = true;
        int neigh = edges[node];

        if(neigh != -1 && !vis[neigh])
        {
            mp[neigh] = mp[node]+1;
            dfs(neigh,edges,mp,vis);
        }
        else if(neigh != -1 && mp.count(neigh))
        {
            res = max(res,mp[node]-mp[neigh]+1);
        }
    }

    int longestCycle(vector<int>& edges) {
        
        
        int n = edges.size();
        vector<bool>vis(n,false);

        for(int i=0;i<edges.size();i++)
        {
            if(!vis[i])
            {
                unordered_map<int,int>mp;
                dfs(i,edges,mp,vis);

            }

        }
        return res;
    }
};
