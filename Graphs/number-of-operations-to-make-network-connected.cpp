class Solution {
public:

    void dfs(int node,vector<vector<int>>& adja,vector<bool>& visited)
    {
        visited[node] = true;
        for(int neigh:adja[node])
        {
            if(!visited[neigh])
            {
                dfs(neigh,adja,visited);
            }
        }

    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adja(n);
        
        if(connections.size() < n-1)
        {
            return -1;
        }

        vector<bool>visited(n);

        for(auto node:connections)
        {
            adja[node[0]].push_back(node[1]);
            adja[node[1]].push_back(node[0]);
        }

        int ans = 0;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                ans++;
                dfs(i,adja,visited);
            }
        }
        return ans-1;
        
    }
};
