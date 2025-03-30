class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]] = i;
        }
        int j = 0,nc  = 0;
        vector<int>res;
        for(int i=0;i<s.size();i++)
        {
            j = max(j,mpp[s[i]]);
            if(i == j)
            {
                res.push_back(i-nc+1);
                nc = i+1;
            }
        }
        return res;
    }
};