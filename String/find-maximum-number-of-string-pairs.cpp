class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        
        set<string>st;
        int res = 0;
        for(auto i:words)
        {
            string rev = i;
            reverse(rev.begin(),rev.end());
            if(st.find(rev) == st.end() || st.find(i) == st.end())
            {
                st.insert(i);
                st.insert(rev);
                
            }
            else
            {
                res++;    
            }
        }
        return res;
        
    }
};
