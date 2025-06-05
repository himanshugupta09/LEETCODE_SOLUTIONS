class Solution {
  public:
    int dfs(int node,int dest,unordered_map<int,vector<int>>&graph,vector<int>&dp)
    {
        
        if(node == dest)
        {
            return 1;
        }
        if(dp[node] != -1)
        {
            return dp[node];
        }
        int res = 0;
        for(int nei:graph[node])
        {
            res += dfs(nei,dest,graph,dp);
        }
        return dp[node] = res;
        
    }
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        
        
        unordered_map<int,vector<int>>graph;
        for(auto edge:edges)
        {
            graph[edge[0]].push_back(edge[1]);
        }
        vector<int>dp(V,-1);
        return dfs(src,dest,graph,dp);
    }
};
