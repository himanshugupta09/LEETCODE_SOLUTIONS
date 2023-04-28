class Solution {
public:

    bool is_similar(string a,string b)
    {
        int cnt = 0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i] != b[i])
            {
                cnt++;
            }
        }
        return (cnt == 0 || cnt == 2);
    }

    void dfs(int i,vector<string>& strs,vector<bool>& vis)
    {
        vis[i] = true;
        for(int j=0;j<strs.size();j++)
        {
            if(vis[j]) continue;
            if(is_similar(strs[i],strs[j]))
            {
                dfs(j,strs,vis);
            }
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int gps = 0;
        vector<bool>vis(n,false);

        for(int i=0;i<strs.size();i++)
        {
            if(vis[i])
            {
                continue;
            }
            gps++;
            dfs(i,strs,vis);
        }
        return gps;
    }
};
