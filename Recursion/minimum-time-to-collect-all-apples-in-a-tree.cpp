class Solution {
public:

    int dfs(int node,int parent,vector<vector<int>>& adj,vector<bool>& verif)
    {
        int minMoves = 0,cT = 0;

        for(auto ch:adj[node])
        {
            if(ch == parent)
            {
                continue;
            }
            cT = dfs(ch,node,adj,verif);

            if(cT || verif[ch])
            {
                minMoves += cT + 2;
            }

        }
        return minMoves;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
         vector<vector<int>> adj(n);

        for(auto ed:edges)
        {
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }

        return dfs(0,-1,adj,hasApple);
    }
};
