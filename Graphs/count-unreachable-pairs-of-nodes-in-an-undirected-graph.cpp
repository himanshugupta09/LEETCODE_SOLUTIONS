class Solution {
public:
    void dfs(vector<int> g[],vector<bool> &vis,int &ans,int v)
    {
        vis[v]=true;
        ans++;
        for (auto i : g[v]) {
        if (vis[i] == false) 
        {
            dfs(g, vis, ans,i );
        }
    }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n,false);
        vector<int> temp;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                int ans=0;
                dfs(adj,vis,ans,i);
                temp.push_back(ans);
            }
        }
        long long res=0;
        for(int i=0;i<temp.size();i++)
        {
            res+=(long long)(temp[i]) * (long long)(n-temp[i]);
        }
        res/=2;
        return res;
    }
};
