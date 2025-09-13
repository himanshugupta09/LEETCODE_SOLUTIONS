class Solution {
public:
    int maxFreqSum(string s) {
        int vowc = 0;
        int coc = 0;
        
        set<char>vows = {'a','e','i','o','u'};
        unordered_map<char,int>mpp;

        for(char i:s)
        {
            mpp[i]++;
            if(vows.find(i) != vows.end())
            {
                if(mpp[i] > vowc)
                {
                    vowc = mpp[i];
                   
                }
            }
            else
            {
                if(mpp[i] > coc)
                {
                    coc = mpp[i];
                   
                }
            }
        }
        return coc+vowc;
    }
};