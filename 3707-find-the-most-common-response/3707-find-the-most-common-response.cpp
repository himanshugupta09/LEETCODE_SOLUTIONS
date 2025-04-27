class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string,int>mpp;
        int maxi = -1;
        string word;
        for(auto list:responses)
        {
            set<string>st;
            for(auto words:list)
            {
                if(st.find(words) == st.end())
                {
                    st.insert(words);
                    mpp[words]++;
                }
            }
        }
        for(auto i:mpp)
        {
            if(i.second > maxi)
            {
                maxi = i.second;
                word = i.first;
            }
        }
        return word;
        
    }
};