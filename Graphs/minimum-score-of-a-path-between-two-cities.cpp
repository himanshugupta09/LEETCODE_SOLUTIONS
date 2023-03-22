class Solution {
public:

    void solve(int node,vector<vector<pair<int,int>>>& adja,vector<bool>& vis,int& res)
    {
        vis[node] = true;
        for(auto& ed:adja[node])
        {
            res = min(res,ed.second);

            if(!vis[ed.first])
            {
                solve(ed.first,adja,vis,res);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
       vector<vector<pair<int,int>>>adja(n+1);

        for(auto& road:roads)
        {
            adja[road[0]].push_back({road[1],road[2]});
            adja[road[1]].push_back({road[0],road[2]});
        }
        vector<bool>vis(n+1);
        int res = INT_MAX;

        solve(1,adja,vis,res);
        return res;
        


    }
};
