class Solution {
public:
    bool isPre(unordered_map<int,vector<int>>&adj,int s,int tar,vector<bool>&vis)
    {
        vis[s]=true;
        if(s == tar)
        {
            return true;
        }
        int res = false;
        for(auto node:adj[s])
        {
            if(!vis[node])
            {
                res = res || isPre(adj,node,tar,vis);
            }
        }
        return res;

    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        for(auto rel:prerequisites)
        {
            adj[rel[0]].push_back(rel[1]);
        }
        vector<bool>res;
        for(auto q:queries)
        {
            vector<bool>vis(numCourses,false);
            res.push_back(isPre(adj,q[0],q[1],vis));
        }
        return res;


    }
};
