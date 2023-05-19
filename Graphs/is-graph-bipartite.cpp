class Solution {
public:

    bool isHelp(vector<vector<int>>& adj,vector<vector<int>>& graph,int src,vector<int>& col)
    {
        col[src] = 1;
        queue<int>q;
        q.push(src);

        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            if(adj[f][f] == 1)
            {
                return false;

            }
            for(int i=0;i<adj[f].size();i++)
            {
                if(adj[f][i] == 1 && col[i] == -1)
                {
                    col[i] = 1 - col[f];
                    q.push(i);
                }
                else if(adj[f][i] && col[i] == col[f])
                {
                    return false;
                }
            }


        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<vector<int>>adj(n,vector<int>(n,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i][graph[i][j]]++;
            }
        }
        vector<int>col(n,-1);

        for(int i=0;i<n;i++)
        {
            if(col[i] == -1)
            {
                if(isHelp(adj,graph,i,col) == false)
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};
