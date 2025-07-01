class Solution {
  public:
    int counter(vector<int>&freq)
    {
        int res  = 0;
        for(auto i:freq)
        {
            if(i != 0)
            {
                res++;
            }
        }
        return res;
    }
    int substrCount(string &s, int k) {
        // code here
        int l = 0;
        int res = 0;
       vector<int>fre(26,0);
        int n = s.size();
        for(int r=0;r<n;r++)
        {
            fre[s[r]-'a']++;
            if(r-k+1 > l) fre[s[l++]-'a']--;
            if(r-k+1 == l && counter(fre) == k-1) res++;
            
        }
        return res;
    }
};
