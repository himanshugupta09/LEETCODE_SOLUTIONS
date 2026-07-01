class Solution {
  public:
    vector<int> zf(string &s)
    {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
    
        for(int i = 1; i < n; i++)
        {
            if(i <= r)
                z[i] = min(r - i + 1, z[i - l]);
    
            while(i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
    
            if(i + z[i] - 1 > r)
            {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }
    vector<int> search(string &pat, string &txt)
    {
        string s = pat + "$" + txt;
        vector<int> z = zf(s);
    
        vector<int> res;
        int m = pat.size();
    
        for(int i = m + 1; i < s.size(); i++)
        {
            if(z[i] == m)
                res.push_back(i - m - 1);
        }
    
        return res;
    }
};
