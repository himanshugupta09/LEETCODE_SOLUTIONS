class Solution {
public:
    int dfs(int node,int par,vector<vector<int>>&child,int k)
    {
        if(k < 0)
        {
            return 0;
        }
        int res = 1;
        for(int ch:child[node])
        {
            if(ch == par)
            {
                continue;
            }
            res += dfs(ch,node,child,k-1);
        }
        return res;
    }
    vector<int>build(vector<vector<int>>&edg,int k)
    {
        int n = edg.size()+1;
        vector<vector<int>>child(n);
        for(auto ed:edg)
        {
            child[ed[0]].push_back(ed[1]);
            child[ed[1]].push_back(ed[0]);
        }
        vector<int>res(n);
        for(int i=0;i<n;i++){
            res[i] = dfs(i,-1,child,k);
        }
        return res;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        
        int  n = edges1.size()+1,m  = edges2.size()+1;
        vector<int>count1 = build(edges1,k);
        vector<int>count2 = build(edges2,k-1);
        int maxi = *max_element(count2.begin(),count2.end());
        vector<int>res(n);
        for(int i=0;i<n;i++)
        {
            res[i] = count1[i]+maxi;
        }
        return res;
    }
};