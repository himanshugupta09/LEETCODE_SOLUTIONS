class Solution {
public:

    int dfs(int curNode,set<int>& vis,unordered_map<int,vector<int>>& mp)
    {
        stack<int>st;
        //set<int>vis;
        st.push(curNode);
        vis.insert(curNode);

        for(auto neigh:mp[curNode])
        {
            if(vis.find(neigh) == vis.end())
            {
                dfs(neigh,vis,mp);
            }
        }

        return vis.size();

    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int res = 0;
        unordered_map<int,vector<int>>mp;
        //set<int>vis;
        int n = bombs.size();

        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i == j)
                {
                    continue;
                }
                int xi = bombs[i][0],yi = bombs[i][1],ri = bombs[i][2];
                int xj = bombs[j][0],yj = bombs[j][1],_ = bombs[j][2];

                if(pow(ri,2) >= pow((xi-xj),2) + pow((yi-yj),2))
                {
                    mp[i].push_back(j);
                }
                 
            }
        }

        for(int i=0;i<n;i++)
        {
            set<int>vis;
            res = max(res,dfs(i,vis,mp));
        }
        return res;



    }
};
