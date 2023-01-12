class Solution {
public:

    vector<int>dfs(int node,int parent,vector<vector<int>>& adj,string& labels,vector<int>& res)
    {

        vector<int>nodeCounts(26);

        nodeCounts[labels[node]-'a'] = 1;

        for(auto child:adj[node])
        {
            if(child == parent)
            {
                continue;
            }
            vector<int>subTree = dfs(child,node,adj,labels,res);

            for(int j=0;j<26;j++)
            {
                nodeCounts[j] += subTree[j];
            }

        }

        res[node] = nodeCounts[labels[node] - 'a'];
        return nodeCounts;


    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<vector<int>> adj(n);
        vector<int>res(n,0);

        for(auto ed:edges)
        {
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }

        

        dfs(0,-1,adj,labels,res);
        return res;


    }
};
