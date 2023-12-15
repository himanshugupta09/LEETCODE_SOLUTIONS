class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string>st;
        unordered_map<string,int>mp;
        
        for(int i=0;i<paths.size();i++)
        {
            st.insert(paths[i][0]);
            st.insert(paths[i][1]);
        }
        
        for(int i=0;i<paths.size();i++)
        {
            mp[paths[i][0]]++;
        }
        string res;
        
        for(auto i:st)
        {
            if(mp.find(i) == mp.end())
            {
                res = i;
                break;
            }
        }
        return res;
    }
};
