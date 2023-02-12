class Solution {
public:

    long long res = 0;
    long long dfs(vector<vector<int>>&adj,int node,vector<bool>& vis,int seats)
    {
        vis[node] = true;
        long long cnt = 1;

        for(int i=0;i<adj[node].size();i++)
        {
            int cur = adj[node][i];

            if(!vis[cur])
            {
                cnt += (dfs(adj,cur,vis,seats));
            }
        }


        long long x = cnt/seats;

        if(cnt%seats) x++;
        
        if(node != 0)
        {
            res += x;
        }

        return cnt;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n = roads.size();
       
        if(n == 0)
        {
            return 0;
        }
        vector<vector<int>>adj(n+1);

        for(int i=0;i<n;i++)
        {
            int x = roads[i][0];
            int y = roads[i][1];

            adj[x].push_back(y);
            adj[y].push_back(x);

        }

        vector<bool>vis(n+1,0);

        dfs(adj,0,vis,seats);

        return res;

    }
};
