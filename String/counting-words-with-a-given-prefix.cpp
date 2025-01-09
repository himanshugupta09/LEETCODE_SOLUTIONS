class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int m = pref.size();
        int n = words.size();
        int res = 0;
        for(int i=0;i<n;i++)
        {
            if(words[i].size() >= m)
            {
                if(words[i].substr(0,m) == pref)
                {
                    res++;
                }
            }
        }
        return res;
    }
};
