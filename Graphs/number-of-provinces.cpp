class Solution {
public:
   

    void dfs(int node,vector<vector<int>>& isConnected,vector<bool>& vis)
    {
        vis[node] = true;
        for(int i=0;i<isConnected.size();i++)
        {
            if(isConnected[node][i]&&!vis[i])
            {
                dfs(i,isConnected,vis);
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        //vector<vector<int>>adj(vector<int>(n,false),n);
        int cnter = 0;
        vector<bool>vis(n);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnter++;
                dfs(i,isConnected,vis);
            }
        }
        return cnter;

       
    }
};
