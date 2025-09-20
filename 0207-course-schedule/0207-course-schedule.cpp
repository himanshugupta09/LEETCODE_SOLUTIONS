class Solution {
public:
    
    bool dfs(vector<vector<int>>&adj,int v,vector<int>&vis)
    {
        vis[v] = 1;
        for(int u:adj[v])
        {
            if(vis[u] == 0)
            {
                if(!dfs(adj,u,vis))
                {
                    return false;
                }
            }
            else if(vis[u] == 1)
            {
                return false;
            }
        }
        vis[v] = 2;
        return true;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>>adj(numCourses);
        vector<int>vis(numCourses,0);
        for(auto p:pre)
        {
            adj[p[1]].push_back(p[0]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i] == 0)
            {
                if(!dfs(adj,i,vis))
                {
                    return false;
                }
            }
        }
        //cout << res.size() << "\n";
        return true;
    }
};