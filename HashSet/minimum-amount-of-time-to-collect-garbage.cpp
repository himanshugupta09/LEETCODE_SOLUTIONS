class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int n = garbage.size();
        int res = 0;
        
        set<char>st;
        
        for(int i=n-1;i>=0;i--)
        {
            for(char c:garbage[i])
            {
                if(st.find(c) == st.end())
                {
                    st.insert(c);
                }
            }
            res += garbage[i].size();
            res += i > 0 ? st.size()*travel[i-1] : 0;
        }
        return res;
    }
};
